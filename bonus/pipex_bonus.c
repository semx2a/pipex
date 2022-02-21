/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:21:08 by seozcan           #+#    #+#             */
/*   Updated: 2022/02/11 12:21:11 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void ft_infile(t_obj obj, char *av, int *pipe, char **envp)
{
	close(pipe[0]);
	dup2(pipe[1], STDOUT_FILENO);
	close(pipe[1]);
	dup2(obj.fd_in, STDIN_FILENO);
	close(obj.fd_in);
	obj.cmd_args = ft_split(av, ' ');
	obj.cmd = get_cmd(obj.paths, obj.cmd_args[0]);
	if (execve(obj.cmd, obj.cmd_args, envp) == -1)
	{	
		ft_free_child(obj.cmd_args, obj.cmd);
		ft_error("Execve returned an error");
	}
}

void ft_outfile(t_obj obj, char *av, int *pipe, char **envp)
{
	close(pipe[1]);
	dup2(pipe[0], STDIN_FILENO);
	close(pipe[0]);
	dup2(obj.fd_out, STDOUT_FILENO);
	close(obj.fd_out);
	obj.cmd_args = ft_split(av, ' ');
	obj.cmd = get_cmd(obj.paths, obj.cmd_args[0]);
	if (execve(obj.cmd, obj.cmd_args, envp) == -1)
	{	
		ft_free_child(obj.cmd_args, obj.cmd);
		ft_error("Execve returned an error");
	}
}
void	ft_close(t_obj obj)
{
	int len;

	len = 0;
	while(len < obj.n_pipe)
	{
		close(obj.fd_pipe[len]);
		len++;
	}
}

void	get_pipes(t_obj obj)
{	
	int t;

	t = 0;
	obj.fd_pipe = (int *)malloc(sizeof(int) * obj.n_pipe);
	while (t < obj.n_pipe)
	{
		if (pipe(obj.fd_pipe + 2 * t) == -1)
			ft_error("Pipe returned an error");
		t++;
	}
}

void ft_pipe(t_obj obj, int ac, char **av, char **envp)
{
	int i;

	obj.n_pipe = ac - 4;
	if ((obj.pid1 = fork()) < 0)
		ft_error("Fork failed");
	get_pipes(obj);
	i = -1;
	if (obj.pid1 == 0)
		while (i++ < obj.n_pipe)
			ft_infile(obj, av[i], &obj.fd_pipe[i], envp);
	if ((obj.pid2 = fork()) < 0)
		ft_error("Fork failed");
	if (obj.pid2 == 0)
		ft_outfile(obj, av[ac - 2], &obj.fd_pipe[i], envp);
	ft_close(obj);
	waitpid(obj.pid1, NULL, 0);
	waitpid(obj.pid2, NULL, 0);
}

int main(int ac, char **av, char **envp)
{
	t_obj obj;

	if (ac < 5)
		ft_error("usage: ./pipex file1 cmd1 cmd2 ... cmdn file2");
	if (*envp == NULL)
		ft_error("Empty environment");
	obj.fd_in = open(av[1], O_RDONLY);
	if (obj.fd_in == -1)
		ft_error("Could not open infile");
	obj.fd_out = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0755);
	if (obj.fd_out == -1)
		ft_error("Could not open outfile");
	obj.cmd_paths = ft_paths(envp);
	obj.paths = ft_split(obj.cmd_paths, ':');
	ft_pipe(obj, ac, av, envp);
	ft_free_parent(obj.paths);
	return (0);
}