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
void    ft_free_tab(char **tab, long int len);
void	ft_print_tab(char **tab);
void	ft_exec(char **nvlst, char **argVec, char **envp);
char	**ft_mkpath(char **nvlst, char **argVec, char **envp);

#endif
