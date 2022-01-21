/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:55:43 by seozcan           #+#    #+#             */
/*   Updated: 2022/01/21 12:56:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_strlen(char *str)
{
	if (*str == '\0')
		return (0);
	return (ft_strlen(str + 1) + 1);
}

int	ft_base_converter(char c, char *base)
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

int	ft_check_base(char *base, int lenbase)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '-' || base[i] == '+'
			|| (base[i] > 8 && base[i] < 14) || base[i] == ' ')
			return (1);
		j = i + 1;
		while (j < lenbase)
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_atoi(char *str, int lenbase, char *base)
{
	int	i;
	int	res;
	int	neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= (-1);
		i++;
	}
	while (str[i] && ft_base_converter(str[i], base) >= 0)
	{
		res = res * lenbase;
		res = res + ft_base_converter(str[i], base);
		i++;
	}
	return (neg * res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	lenbase;

	lenbase = ft_strlen(base);
	if (ft_check_base(base, lenbase) == 1)
		return (0);
	return (ft_atoi(str, lenbase, base));
}
