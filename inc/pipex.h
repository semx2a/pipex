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
# include <string.h>
# include "../ft_printf/inc/ft_printf.h"

typedef struct s_obj
{
    int fd_in;
    int fd_out;
    int fd_pipe[2];
    pid_t pid1;
    pid_t pid2;
    char    *cmd;
    char    **cmd_args;
    char    *cmd_paths;
    char    **paths;
}  t_obj;

int ft_tablen(char **tab);
int	ft_tablen(char **tab);
void	ft_error(const char *str);
void	ft_close(int **fd_pipe, int len);
void    ft_free_child(char **args, char *arg);
void    ft_free_parent(char **args);
char	*ft_paths(char **envp);
char    *get_cmd(char **paths, char *cmd);
char	**ft_tabcpy(char **dst, char **src);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char a);
char    *ft_substr(char const *s, char *d, size_t start, size_t len);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);

#endif
