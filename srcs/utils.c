/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:15:17 by seozcan           #+#    #+#             */
/*   Updated: 2022/02/21 15:15:50 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_error(const char *str)
{
	write(2, str, ft_strlen(str));
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	exit(EXIT_FAILURE);
}

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != 0)
		len++;
	return (len);
}

void	ft_free_child(char **args, char *arg)
{
	while (*args != 0)
		free(*args++);
	free(args);
	free(arg);
}

void	ft_free_parent(char **args)
{
	int	i;

	i = 0;
	while (args[i] != 0)
	{
		free(args[i]);
		i++;
	}
	free(args);
}
