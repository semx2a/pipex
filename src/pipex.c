/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:57:05 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/01 17:44:16 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_infile(t_obj obj, char *av, char **envp)
{
	close(obj.fd_pipe[0]);
	dup2(obj.fd_pipe[1], STDOUT_FILENO);
	close(obj.fd_pipe[1]);
	dup2(obj.fd_in, STDIN_FILENO);
	close(obj.fd_in);
	obj.cmd_args = ft_split(av, ' ');
	obj.cmd = get_cmd(obj.paths, obj.cmd_args[0]);
	if (execve(obj.cmd, obj.cmd_args, envp) == -1)
	{	
		ft_free_child(obj.cmd_args);
		ft_free_parent(obj.paths);
		exit(ft_error("pipex ", "Execve returned an error: "));
	}
}

void	ft_outfile(t_obj obj, char *av, char **envp)
{
	close(obj.fd_pipe[1]);
	dup2(obj.fd_pipe[0], STDIN_FILENO);
	close(obj.fd_pipe[0]);
	dup2(obj.fd_out, STDOUT_FILENO);
	close(obj.fd_out);
	obj.cmd_args = ft_split(av, ' ');
	obj.cmd = get_cmd(obj.paths, obj.cmd_args[0]);
	if (execve(obj.cmd, obj.cmd_args, envp) == -1)
	{	
		ft_free_child(obj.cmd_args);
		ft_free_parent(obj.paths);
		exit(ft_error("pipex ", "Execve returned an error: "));
	}
}

void	ft_pipe(t_obj obj, char **av, char **envp)
{
	if (pipe(obj.fd_pipe) == -1)
		exit(ft_error("pipex ", "Pipe failed: "));
	obj.pid1 = fork();
	if (obj.pid1 == -1)
		exit(ft_error("pipex ", "Fork_in failed: "));
	if (obj.pid1 == 0)
		ft_infile(obj, av[2], envp);
	obj.pid2 = fork();
	if (obj.pid2 == -1)
		exit(ft_error("pipex ", "Fork_out failed: "));
	if (obj.pid2 == 0)
		ft_outfile(obj, av[3], envp);
	close(obj.fd_pipe[0]);
	close(obj.fd_pipe[1]);
	ft_free_parent(obj.paths);
	waitpid(obj.pid1, NULL, 0);
	waitpid(obj.pid2, NULL, 0);
}

int	main(int ac, char **av, char **envp)
{
	t_obj	obj;

	if (ac != 5)
		exit(ft_error("pipex ", "usage: ./pipex file1 cmd1 cmd2 file2"));
	if (*envp == NULL)
		exit(ft_error("pipex ", "Empty environment"));
	obj.fd_in = open(av[1], O_RDONLY);
	if (obj.fd_in == -1)
		exit(ft_error("pipex ", "Could not open infile: "));
	obj.fd_out = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (obj.fd_out == -1)
		exit(ft_error("pipex ", "Could not open outfile: "));
	obj.cmd_paths = ft_paths(envp);
	obj.paths = ft_split(obj.cmd_paths, ':');
	ft_pipe(obj, av, envp);
	return (0);
}
