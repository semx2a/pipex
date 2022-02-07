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
	path = ft_path(cmd[0], envp);
	if (execve(path, (char * const*)cmd, (char * const*)envp) == -1)
		ft_error("Could not execute path.");
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
		if (src[0] == '.' && src[1] == '/')
		{
			free(dst);
			dst[i] = ft_strdup("./");
		}
		else
			dst[i] = ft_strjoin(dst[i], "/");
		dst[i] = ft_strjoin(dst[i], src);
		if (access(dst[i], X_OK) == 0)
			return (dst[i]);
		i++;
	}
	ft_free_tab(dst, ft_tablen(dst));
	ft_error("Could not find path.");
	return (0);
}
