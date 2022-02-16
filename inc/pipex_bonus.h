/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:21:23 by seozcan           #+#    #+#             */
/*   Updated: 2022/02/11 12:21:29 by seozcan          ###   ########.fr       */
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
# include "../libft/inc/libft.h"

typedef struct s_obj
{
    int fd_in;
    int fd_out;
    int fd_pipe[2];
    int cmdn;
    int pipen;
    pid_t pid1;
    pid_t pid2;
    char    **cmd;
    char    *path;
}  t_obj;

int ft_tablen(char **tab);
void	ft_error(const char *str);
void	ft_exec(t_obj obj, char *av, char **envp);
char	*ft_path(char *src, char **envp);
char	**ft_tabcpy(char **dst, char **src);
void	ft_close(int **fd_pipe, int len);

#endif
