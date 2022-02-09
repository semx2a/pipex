/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 14:57:05 by seozcan           #+#    #+#             */
/*   Updated: 2022/01/24 18:06:06 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void ft_pipe(t_obj obj, char *av, char **envp)
{
	if (pipe(obj.fd_pipe) == -1)
		ft_error("Pipe returned an error");
	if ((obj.pid = fork()) < 0)
		ft_error("Fork failed");
	if (obj.pid == 0)
	{
		close(obj.fd_pipe[0]);
		dup2(obj.fd_pipe[1], STDOUT_FILENO);
		close(obj.fd_pipe[1]);
		ft_exec(obj, av, envp);
	}
	else
	{
		waitpid(0, NULL, 0);
		close(obj.fd_pipe[1]);
		dup2(obj.fd_pipe[0], STDIN_FILENO);
		close(obj.fd_pipe[0]);
	}
}

int main(int ac, char **av, char **envp)
{
	t_obj obj;
	int i;

	i = 2;
	if (ac >= 5)
	{
		if (*envp == NULL)
			ft_error("Empty environment");
		if (!(obj.fd_in = open(av[1], O_RDONLY)))
			ft_error("Could not read input file");
		dup2(obj.fd_in, STDIN_FILENO);
		close (obj.fd_in);
		while (i < (ac - 2))
			ft_pipe(obj, av[i++], envp);
		obj.fd_out = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0755);
		if (obj.fd_out == -1)
			ft_error("Could not create output file");
		dup2(obj.fd_out, STDOUT_FILENO);
		close(obj.fd_out);
		ft_exec(obj, av[ac - 2], envp);
	}
	ft_error("usage: ./pipex file1 cmd1 cmd2 ... cmdn file2");
	return (0);
}
