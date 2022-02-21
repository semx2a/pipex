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

void ft_infile(t_obj obj, char *av, char **envp)
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
		ft_free_child(obj.cmd_args, obj.cmd);
		ft_error("Execve returned an error");
	}
}

void ft_outfile(t_obj obj, char *av, char **envp)
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
		ft_free_child(obj.cmd_args, obj.cmd);
		ft_error("Execve returned an error");
	}
}

void ft_pipe(t_obj obj, int ac, char **av, char **envp)
{
	int i;
	int **fd_pipe;
	int	t;
	int	n_pipe;

	i = 2;
	t = 0;
	n_pipe = ac - 4;
	while (t < n_pipe)
	{
		fd_pipe[t] = t;
		if (pipe(fd_pipe[t]) == -1)
			ft_error("Pipe returned an error");
		t++;
	}
	if ((obj.pid1 = fork()) < 0)
		ft_error("Fork failed");
	if (obj.pid1 == 0)
	{
		while (i < ac - 2)
		{
			ft_infile(obj, av[i], fd_pipe[i -2], envp);
			i++;
		}
	}
	if ((obj.pid2 = fork()) < 0)
		ft_error("Fork failed");
	if (obj.pid2 == 0)
		ft_outfile(obj, av[ac - 2], fd_pipe[i - 2], envp);
	waitpid(obj.pid1, NULL, 0);
	waitpid(obj.pid2, NULL, 0);
	ft_close(fd_pipe, n_pipe);
}

int main(int ac, char **av, char **envp)
{
	t_obj obj;
	if (ac >= 5)
	{
		if (*envp == NULL)
			ft_error("Empty environment");
		obj.fd_in = open(av[1], O_RDONLY);
		if (obj.fd_in == -1)
			ft_error("Could not read input file");
		dup2(obj.fd_in, STDIN_FILENO);
		close(obj.fd_in);
		obj.fd_out = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0755);
		if (obj.fd_out == -1)
			ft_error("Could not create output file");
		dup2(obj.fd_out, STDOUT_FILENO);
		close(obj.fd_out);
		ft_pipe(obj, av, envp);
	}
	ft_error("usage: ./pipex file1 cmd1 cmd2 ... cmdn file2");
	return (0);
}
