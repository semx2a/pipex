/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:51:07 by seozcan           #+#    #+#             */
/*   Updated: 2021/11/30 19:43:15 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	a = c;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == a)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == '\0' && a == 0)
		return ((char *)s + ft_strlen(s));
	return (0);
}
