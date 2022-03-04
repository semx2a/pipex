/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:50:50 by seozcan           #+#    #+#             */
/*   Updated: 2022/02/22 20:50:52 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	ft_error(const char *str)
{
	write(2, "ERR:\t", 5);
	write(2, str, ft_strlen(str));
	if (ft_strnstr(strerror(errno), "Success", 7) == 0)
		write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	ft_free_child(t_obj *obj)
{
	int	i;

	i = 0;
	while (obj->cmd_flags[i] != 0)
	{
		free(obj->cmd_flags[i]);
		i++;
	}
	free(obj->cmd_flags);
}

void	ft_free_parent(t_obj *obj)
{
	int	i;

	i = 0;
	close(obj->fd_in);
	close(obj->fd_out);
	while (obj->paths[i] != 0)
	{
		free(obj->paths[i]);
		i++;
	}
	free(obj->paths);
	i = 0;
	while (obj->cmds[i] != 0)
	{
		free(obj->cmds[i]);
		i++;
	}
	free(obj->cmds);
	free(obj->fd_pipe);
}

void	ft_close_pipes(t_obj *obj)
{
	int	i;

	i = 0;
	while (i < (obj->pipe_nb * 2))
	{
		close(obj->fd_pipe[i]);
		i++;
	}
}
