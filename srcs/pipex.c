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

int	main(int ac, char **av, char **envp)
{
	char	**nvlst;
	int	i;

	i = 0;
	nvlst = NULL;
	if (ac > 1)
	{
		if (!envp)
			return (0);
		while (envp[i])
		{
			if (ft_strnstr(envp[i], "PATH", 5))
			{
				nvlst = ft_split(envp[i] + 5, ':');
				break;
			}
			i++;
		}
		i = 0;
		while (nvlst[i])
		{
			nvlst[i] = ft_strjoin(nvlst[i], "/");
			nvlst[i] = ft_strjoin(nvlst[i], av[1]);
			i++;
		}
		i = 0;
		while (nvlst[i])
		{
			if (access(nvlst[i], F_OK))
			{
				if (!execve(nvlst[i], (char * const*)av[2], (char * const*)envp))
				{	
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
					execve(nvlst[i], (char * const*)av[2], (char * const*)envp);
			}
			i++;
		}
//		ft_print_tab(nvlst);
		ft_free_tab(nvlst, ft_tablen(nvlst));
	}
	return (0);
}
