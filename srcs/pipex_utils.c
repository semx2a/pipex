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

void	ft_error(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}


void	ft_exec(char *arg, char **envp)
{
	char	*path;
	char	**cmd;

	cmd = ft_split(arg, ' ');
	if ((access(cmd[0], X_OK)) == 0)
		path = ft_strdup(cmd[0]);
	else
		path = ft_path(cmd[0], envp);
	if (execve(path, (char * const*)cmd, (char * const*)envp) == -1)
	{
		ft_free_tab(cmd, ft_tablen(cmd));
		free(path);
		ft_error("Could not execute path");
	}
}

char	*ft_path(char *src, char **envp)
{
	int	i;
	char	**dst;

	i = 0;
	dst = NULL;
	while (ft_strnstr(envp[i], "PATH", 5) == 0)
		i++;
	dst = ft_split(envp[i] + 5, ':');
	i = 0;
	while (dst[i])
	{
		dst[i] = ft_strjoin(dst[i], "/");
		dst[i] = ft_strjoin(dst[i], src);
		if (access(dst[i], X_OK) == 0)
			return (dst[i]);
		else if (!dst[i + 1])
		{
			ft_free_tab(dst, ft_tablen(dst));
			ft_error("Command not found");
		}
		i++;
	}
	return (0);
}
