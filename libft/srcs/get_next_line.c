/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 21:27:42 by seozcan           #+#    #+#             */
/*   Updated: 2022/01/14 10:11:29 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*set_head(char *head)
{
	char	*new_head;
	int		i;

	if (!head)
		return (NULL);
	i = 0;
	if (!head[i])
	{
		free(head);
		return (NULL);
	}
	while (head[i] && head[i] != '\n')
		i++;
	if (head[i] == '\n')
		i++;
	new_head = NULL;
	new_head = ft_substr(head, i, (ft_strlen(head) - i));
	if (!new_head)
		free(new_head);
	free(head);
	return (new_head);
}

char	*get_line(char *ln, char *head)
{
	int		i;

	i = 0;
	if (!head[i])
		return (NULL);
	while (head[i] && head[i] != '\n')
		i++;
	if (head[i] == '\n')
		i++;
	ln = ft_substr(head, 0, i);
	if (!ln)
		free(ln);
	return (ln);
}

char	*append_lines(int fd, char *buff, char *head)
{
	int			state;

	state = 1;
	while (!ft_strchr(head, '\n') && state != 0)
	{
		buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		state = read(fd, buff, BUFFER_SIZE);
		if (state == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[state] = '\0';
		head = ft_strjoin(head, buff);
		free(buff);
	}
	return (head);
}

char	*get_next_line(int fd)
{
	static char	*head[1024];
	char		*buff;
	char		*ln;

	if (fd <= -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = NULL;
	head[fd] = append_lines(fd, buff, head[fd]);
	if (!head[fd])
		return (NULL);
	ln = NULL;
	ln = get_line(ln, head[fd]);
	head[fd] = set_head(head[fd]);
	if (!head[fd])
	{
		free(head[fd]);
		return (NULL);
	}
	return (ln);
}
