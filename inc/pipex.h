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
# include "../libft/inc/libft.h"

int ft_tablen(char **tab);
void    ft_child(int *fd, char **argVec, char **envp);
void    ft_mother(int *fd, char **argVec, char **envp);
void	ft_exec(char *arg, char **envp);
char	*ft_path(char *src, char **envp);
char	*ft_path(char *src, char **envp);
char	**ft_args(char **dst, char **src);

#endif
