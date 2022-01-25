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

int	main(int ac, char **av, char **env)
{
	char	**nvlst;
	int	i;

	i = 0;
	nvlst = NULL;
	if (ac > 1)
	{
		if (!env)
			return (0);
		while (env[i])
		{
			if (ft_strnstr(env[i], "PATH", 5))
			{
				nvlst = ft_split(env[i] + 5, ':');
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
				if (!execve(nvlst[i], (char * const*)av[2], (char * const*)"NULL"))
				{	
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
					execve(nvlst[i], (char * const*)av[2], (char * const*)"NULL");
			}
			i++;
		}
		ft_print_tab(nvlst);
		ft_free_tab(nvlst, ft_tablen(nvlst));
	}
	return (0);
}
