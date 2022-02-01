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

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

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
		ft_error("Could not execute path.")
}

char	*ft_path(char *src, char **envp)
{
	int	i;
	char	**dst;

	i = 0;
	dst = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 5))
		{
			dst = ft_split(envp[i] + 5, ':');
			i = 0;
			while (dst[i])
			{
				dst[i] = ft_strjoin(dst[i], "/");
				dst[i] = ft_strjoin(dst[i], src);
				if (access(dst[i], X_OK) == 0)
					return (dst[i]);
				i++;
			}
		}
		i++;
	}
	return (0);
}

char	**ft_tabcpy(char **dst, char **src)
{
	int	i;

	dst = (char **)malloc(sizeof(char *) * ft_tablen(src));
	if(!dst)
		return (0);
	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}