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

void ft_child(char **argVec, char **envp)
{
	ft_exec(argVec[], envp)
}

void ft_mother(char **argVec, char **envp)
{
	ft_exec(argVec[], envp);
}

int main(int ac, char **av, char **envp)
{
	char **argVec;
	int pid;
	int i;

	if (ac > 1)
	{
		if (!envp)
			return (0);
		argVec = NULL;
		argVec = ft_args(argVec, av);
		i = 0;
//		while (i < (ft_tablen(argVec) - 1) / 2)
//		{
			pid = fork();
//			i++;
//		}
		if (pid == -1)
		{
			perror("Fork failed");
			exit(EXIT_FAILURE);
		}
		if (pid > 0)
			ft_child(argVec, envp);
		if (pid == 0)
			ft_mother(argVec, envp);
		ft_free_tab(argVec, ft_tablen(argVec));
	}
	return (0);
}
