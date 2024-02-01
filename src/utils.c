/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:15:17 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/01 17:44:21 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
