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

void ft_cmd1(t_obj obj, char **envp)
{
	if ((obj.pid1 = fork() < 0))
		ft_error("Fork1 failed.\n");
	if (obj.pid1 == 0)
	{
		dup2(obj.fd_in, STDIN_FILENO);
		close(obj.fd_in);
		dup2(obj.fd_pipe[1], STDOUT_FILENO);
		close(obj.fd_pipe[1]);
		close(obj.fd_pipe[0]);
		ft_exec(obj.argVec[1], envp);
	}
}

void ft_cmd2(t_obj obj, char **envp)
{
	if ((obj.pid2 = fork() < 0))
		ft_error("Fork2 failed.\n");
	if (obj.pid2 == 0)
	{
		dup2(obj.fd_out, STDOUT_FILENO);
		close(obj.fd_out);
		dup2(obj.fd_pipe[0], STDIN_FILENO);
		close(obj.fd_pipe[0]);
		close(obj.fd_pipe[1]);
		ft_exec(obj.argVec[2], envp);
	}
}

void ft_pipex(t_obj obj, char **envp)
{
	if (pipe(obj.fd_pipe) < 0)
		ft_error("Pipe returned an error.\n");
	ft_cmd1(obj, envp);
	ft_cmd2(obj, envp);
	close(obj.fd_in);
	close(obj.fd_out);
	close(obj.fd_pipe[0]);
	close(obj.fd_pipe[1]);
	waitpid(obj.pid1, NULL, 0);
	waitpid(obj.pid2, NULL, 0);
}

int main(int ac, char **av, char **envp)
{
	t_obj obj;

	if (ac > 1)
	{
		if (!envp)
			return (0);
		obj.argVec = NULL;
		obj.argVec = ft_tabcpy(obj.argVec, av + 1);
		obj.fd_in = open(obj.argVec[0], O_RDONLY);
		if (obj.fd_in <= 0)
			ft_error("Could not open input file.");
//		printf("fd_in[%i] : %s\n", obj.fd_in, obj.argVec[0]);	
		obj.fd_out = open(obj.argVec[ft_tablen(obj.argVec) - 1], O_CREAT | O_TRUNC | O_WRONLY);
		if (obj.fd_out <= 0)
			ft_error("Could not create output file.");
//		printf("fd_out[%i] : %s\n", obj.fd_out, obj.argVec[ft_tablen(obj.argVec) - 1]);
		ft_pipex(obj, envp);
		ft_free_tab(obj.argVec, ft_tablen(obj.argVec));
	}
	return (0);
}
