/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:46:54 by seozcan           #+#    #+#             */
/*   Updated: 2022/02/22 20:46:56 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/functions.h"

char	*ft_substr(char const *s, char *d, size_t start, size_t len)
{
	size_t	i;
	size_t	slen;

	if (!s)
		return (0);
	i = 0;
	slen = ft_strlen(s);
	if (start >= slen)
	{
		d = (char *)malloc(sizeof(char) * 1);
		d[i] = '\0';
	}
	else if (len >= slen)
		d = (char *)malloc(sizeof(char) * ((slen - start) + 1));
	else
		d = (char *)malloc(sizeof(char) * (len + 1));
	if (!d)
		return (0);
	while (len-- && slen >= start)
		d[i++] = s[start++];
	d[i] = '\0';
	return (d);
}
