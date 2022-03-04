/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 12:21:08 by seozcan           #+#    #+#             */
/*   Updated: 2022/02/28 14:29:52 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex_bonus.h"

void	ft_assign_pipes(t_obj *obj)
{
	int	i;

	i = 0;
	obj->fd_pipe = malloc(sizeof(int *) * (obj->pipe_nb * 2));
	if (!obj->fd_pipe)
		ft_error("Memory allocation has failed: ");
	while (i <= obj->cmd_nb - 1)
	{
		if (pipe(obj->fd_pipe + (2 * i)) == -1)
			ft_error("Pipe failed: ");
		i++;
	}
}

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

void	ft_list_cmds(t_obj *obj, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	obj->cmds = malloc(sizeof(char *) * (obj->cmd_nb + 1));
	if (!obj->cmds)
		ft_error("Memory allocation has failed: ");
	while (++i < ac - 1)
	{
		obj->cmds[j] = ft_strdup(av[i]);
		j++;
	}
	obj->cmds[j] = 0;
}

int	main(int ac, char **av, char **envp)
{
	t_obj	obj;

	if (ac < 5)
		ft_error("usage: ./pipex file1 cmd1 cmd2 ... cmdn file2");
	if (*envp == NULL)
		ft_error("Empty environment");
	obj.fd_in = open(av[1], O_RDONLY);
	if (obj.fd_in == -1)
		ft_error("Could not open infile: ");
	obj.fd_out = open(av[ac - 1], O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (obj.fd_out == -1)
		ft_error("Could not open outfile: ");
	obj.cmd_nb = ac - 3;
	obj.pipe_nb = obj.cmd_nb - 1;
	ft_list_cmds(&obj, ac, av);
	ft_assign_pipes(&obj);
	obj.cmd_paths = ft_paths(envp);
	obj.paths = ft_split(obj.cmd_paths, ':');
	obj.index = -1;
	while (++obj.index < obj.cmd_nb)
		ft_process(obj, envp);
	ft_close_pipes(&obj);
	ft_free_parent(&obj);
	waitpid(-1, NULL, 0);
	return (0);
}
