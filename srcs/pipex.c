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

void	ft_exec(char **nvlst, char **argVec, char **envp)
{
	int	i;

	i = 0;
	while (nvlst[i])
	{
		if (access(nvlst[i], X_OK) == 0)
		{
			if (execve(nvlst[i], (char * const*)argVec, (char * const*)envp) < 0)
			{	
				perror("Could not execute execve");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

char	**ft_mkpath(char **nvlst, char **argVec, char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
		{
			nvlst = ft_split(envp[i] + 5, ':');
			i = 0;
			while (nvlst[i])
			{
				nvlst[i] = ft_strjoin(nvlst[i], "/");
				nvlst[i] = ft_strjoin(nvlst[i], argVec[0]);
				i++;
			}
			return (nvlst);
		}
		i++;
	}
	return (nvlst);
}

int	main(int ac, char **av, char **envp)
{
	char	**nvlst;
	char	**argVec;
	int	i;

	if (ac > 1)
	{
		if (!envp)
			return (0);
		nvlst = NULL;
		argVec = (char **)malloc(sizeof(char *) * ft_tablen(av));
		i = 0;
		while (av[i + 1])
		{
			argVec[i] = av[i + 1];
			i++;
		}
		argVec[i] = 0;
		nvlst = ft_mkpath(nvlst, argVec, envp);
		ft_exec(nvlst, argVec, envp);
		ft_free_tab(nvlst, ft_tablen(nvlst));
		ft_free_tab(argVec, ft_tablen(argVec));
	}
	return (0);
}
