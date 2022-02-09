/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 15:04:42 by seozcan           #+#    #+#             */
/*   Updated: 2022/01/19 11:40:34 by seozcan          ###   ########.fr       */
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
# include "../libft/inc/libft.h"

typedef struct s_obj
{
    int fd_in;
    int fd_out;
    int fd_pipe[2];
    pid_t pid;
    char    **cmd;
}  t_obj;

int ft_tablen(char **tab);
void	ft_error(const char *str);
void	ft_exec(t_obj obj, char *arg, char **envp);
char	*ft_path(char *src, char **envp);
char	**ft_tabcpy(char **dst, char **src);

#endif
