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

void ft_child(int *fd, char **argVec, char **envp)
{
	int i;

	i = 0;
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	ft_exec(argVec[i], envp);
}

void ft_mother(int *fd, char **argVec, char **envp)
{
	int i;

	i = 1;
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(fd[0]);
	ft_exec(argVec[i], envp);
}

void	ft_pipex(char **argVec, char **envp)
{
	int pid1;
	int	pid2;
	int	fd[2];

	if (pipe(fd[0]) < 0)
		ft_error("Pipe returned an error.\n");
	if ((pid1 = fork() < 0))
		ft_error("Fork1 failed.\n");
	if (pid1 == 0)
		ft_child(fd, argVec, envp);	
	if ((pid2 = fork() < 0))
		ft_error("Fork2 failed.\n");
	if (pid1 == 0)
		ft_child(fd, argVec, envp);
	waitpid(pid1, NULL, WNOHANG);	
	waitpid(pid2, NULL, WNOHANG);
	close(fd[0][0]);
	close(fd[1][1]);
	ft_mother(fd, argVec, envp);
}

int main(int ac, char **av, char **envp)
{
	char **argVec;
	
	if (ac > 1)
	{
		if (!envp)
			return (0);
		argVec = NULL;
		argVec = ft_tabcpy(argVec, av + 1);
		ft_pipex(argVec, envp);
		ft_free_tab(argVec, ft_tablen(argVec));
	}
	return (0);
}
