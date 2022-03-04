/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 15:16:11 by seozcan           #+#    #+#             */
/*   Updated: 2022/02/21 15:16:48 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	*ft_paths(char **envp)
{
	while (*envp != 0)
	{
		if (ft_strnstr(*envp, "PATH", 5))
			return (*envp + 5);
		envp++;
	}
	ft_error("env 'PATH' not found");
	return (NULL);
}

char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*ret;

	if (access(cmd, 0) == 0)
		return (cmd);
	else
	{
		while (*paths)
		{
			tmp = ft_strjoin(*paths, "/");
			ret = ft_strjoin(tmp, cmd);
			if (access(ret, 0) == 0)
				return (ret);
			free(ret);
			paths++;
		}
		ft_error("Command not found: ");
	}
	return (NULL);
}
