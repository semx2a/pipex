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

void	ft_exec(char **nvlst, char **argVec, char **envVec)
{
	int	i;

	i = 0;
	while (nvlst[i])
	{
		if (access(nvlst[i], F_OK))
		{
			if (execve(nvlst[i], (char * const*)argVec, (char * const*)envVec) < 0)
			{	
				perror("Could not execute execve");
				exit(EXIT_FAILURE);
			}
		}
		i++;
	}
}

void	ft_mkpath(char **nvlst, char **argVec, char **envp)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
		{
			nvlst = ft_split(envp[i] + 5, ':'); // faire un strjoin pour mettre les /
			break;
		}
		i++;
	}
    i = 0;
	while (nvlst[i])
	{
		nvlst[i] = ft_strjoin(nvlst[i], "/");
		if (access(ft_strjoin(nvlst[i], argVec[j]), F_OK))
		{
			nvlst[i] = ft_strjoin(nvlst[i], argVec[j]);
			break;
		}
		i++;
	}
}
int	main(int ac, char **av, char **envp)
{
	char	**nvlst;
	char	**argVec;
	char	**envVec;
	int	i;

	if (ac > 1)
	{
		if (!envp)
			return (0);
		nvlst = NULL;
		argVec = NULL;
		envVec = NULL;
		i = 0;
		while (av[i + 1])
		{
			ft_memcpy(argVec[i], av[i + 1], ft_strlen(av[i +1]));
			i++;
		}
		ft_mkpath(nvlst, argVec, envp);
		ft_exec(nvlst, argVec, envVec);
//		ft_print_tab(nvlst);
		ft_free_tab(nvlst, ft_tablen(nvlst));
	}
	return (0);
}
