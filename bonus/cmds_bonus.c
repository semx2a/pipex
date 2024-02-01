/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:50:30 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/01 17:43:50 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*get_cmd(char **paths, char *cmd)
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
		exit(ft_error("pipex ", "Command not found: "));
	}
	return (NULL);
}

static void	ft_dup2(int read, int write)
{
	dup2(read, STDIN_FILENO);
	dup2(write, STDOUT_FILENO);
}

void	ft_process(t_obj o, char **envp)
{
	o.pid = fork();
	if (o.pid < 0)
		exit(ft_error("pipex ", "Fork failed: "));
	else if (o.pid == 0)
	{
		if (o.index == 0)
			ft_dup2(o.fd_in, o.fd_pipe[1]);
		else if (o.index == o.cmd_nb - 1)
			ft_dup2(o.fd_pipe[2 * o.index - 2], o.fd_out);
		else
			ft_dup2(o.fd_pipe[2 * o.index - 2], o.fd_pipe[2 * o.index + 1]);
		ft_close_pipes(&o);
		o.cmd_flags = ft_split(o.cmds[o.index], ' ');
		o.cmd = get_cmd(o.paths, o.cmd_flags[0]);
		if (execve(o.cmd, o.cmd_flags, envp) == -1)
		{
			ft_free_child(&o);
			ft_free_parent(&o);
			exit(ft_error("pipex ", "Execve returned an error: "));
		}
	}
}
