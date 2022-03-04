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
	write(2, "ERR:\t", 5);
	write(2, str, ft_strlen(str));
	if (ft_strnstr(strerror(errno), "Success", 7) == 0)
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_free_child(char **args)
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
