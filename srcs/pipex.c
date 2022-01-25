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

int	ft_tablen(char **s)
{
	int	i;

	i = 1;
	while (s[1][i])
		i++;
	return (i);
}

void	ft_print_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

void	ft_argcat(char **tab, char *s)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_strcat(tab[i], "/");
		ft_strcat(tab[i], s);
		i++;
	}
	tab[i] = 0;
}

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
				nvlst = ft_split(env[i] + 5, ':');
			i++;
		}
		ft_argcat(nvlst, av[1]);
		i = 0;
		while (nvlst[i])
		{
			if (access(nvlst[i], F_OK))
			{
				if (!execve(nvlst[i], (char * const*)av[1], (char * const*)"NULL"))
				{	
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
					execve(nvlst[i], (char * const*)av[1], (char * const*)"NULL");
			}
			i++;
		}
		ft_print_tab(nvlst);
	}
	return (0);
}
