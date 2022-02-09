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

void	ft_error(const char *str)
{
	perror(str);
	strerror(errno);
	exit(errno);
}

void	ft_exec(t_obj obj, char *arg, char **envp)
{
	obj.cmd = ft_split(arg, ' ');
	execve(obj.cmd[0], (char * const*)obj.cmd, (char * const*)envp);
	execve((ft_path(obj.cmd[0], envp)), (char * const*)obj.cmd, (char * const*)envp);
	ft_free_tab(obj.cmd, ft_tablen(obj.cmd));
	ft_error("Command not found");
}

char	*ft_path(char *src, char **envp)
{
	int	i;
	char	**tmp;
	char	*dst;

	i = 0;
	tmp = NULL;
	while (ft_strnstr(envp[i], "PATH", 5) == 0)
		i++;
	tmp = ft_split(envp[i] + 5, ':');
	i = 0;
	while (tmp[i])
	{
		tmp[i] = ft_strjoin(tmp[i], "/");
		dst = ft_strjoin(tmp[i], src);
		if (access(dst, X_OK) == 0)
			return (dst);
		i++;
	}
	return ("null");
}
