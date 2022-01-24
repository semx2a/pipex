/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:46:57 by seozcan           #+#    #+#             */
/*   Updated: 2022/01/24 17:47:01 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_chrcheck(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;
	int	baselen;

	i = 0;
	j = 0;
	baselen = ft_strlen(base);
	if (baselen < 2)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] == 32 || ft_isdigit(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	unsigned int	r;
	int				n;
	int				baselen;

	i = 0;
	r = 0;
	n = 1;
	baselen = ft_strlen(base);
	if (!ft_check_base(base))
		return (0);
	while (str[i] == 32 || ft_isdigit(str[i]))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			n = n * -1;
		i++;
	}
	while (ft_chrcheck(str[i], base) >= 0)
	{
		r = r * baselen + ft_chrcheck(str[i], base);
		i++;
	}
	return (r * n);
}
