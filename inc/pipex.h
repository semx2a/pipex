/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:04:42 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/01 16:01:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

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
	int		fd_pipe[2];
	pid_t	pid1;
	pid_t	pid2;
	char	*cmd;
	char	**cmd_args;
	char	*cmd_paths;
	char	**paths;
}	t_obj;

/* utils.c */
void	ft_free_child(char **args);
void	ft_free_parent(char **args);

/* cmds.c */
char	*ft_paths(char **envp);
char	*get_cmd(char **paths, char *cmd);

#endif
