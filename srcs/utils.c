/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:56:44 by seozcan           #+#    #+#             */
/*   Updated: 2022/01/25 19:56:47 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void ft_error(const char *str)
{
	(void)str;

	ft_printf("Value of errno: %d\n", errno);
	ft_printf("Error opening the file: %s\n", strerror(errno));
	perror("Error printed by perror");
	exit(EXIT_FAILURE);
}

int ft_tablen(char **tab)
{
	int len;

	len = 0;
	while (tab[len] != 0)
		len++;
	return (len);
}

void ft_free_child(char **args, char *arg)
{
	while (*args != 0)
		free(*args++);
	free(args);
	free(arg);
}

void ft_free_parent(char **args)
{
	int i;

	i = 0;
	while (args[i] != 0)
	{
		free(args[i]);
		i++;
	}
	free(args);
}