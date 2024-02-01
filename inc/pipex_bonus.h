/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:21:23 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/01 17:43:59 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "libft.h"

typedef struct s_obj
{
	int		fd_in;
	int		fd_out;
	int		pipe_nb;
	int		cmd_nb;
	int		*fd_pipe;
	int		index;
	pid_t	pid;
	char	*cmd;
	char	**cmds;
	char	**cmd_flags;
	char	*cmd_paths;
	char	**paths;
}	t_obj;

/* cmds_bonus.c */
void	ft_process(t_obj o, char **envp);

/* utils_bonus.c */
void	ft_free_child(t_obj *obj);
void	ft_free_parent(t_obj *obj);
void	ft_close_pipes(t_obj *obj);

#endif
