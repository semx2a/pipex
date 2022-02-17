/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 20:01:09 by seozcan           #+#    #+#             */
/*   Updated: 2021/12/13 20:01:11 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_parse(va_list args, int i, const char *str)
{
	if (str[i] == '%')
		i = ft_putstr("%");
	else if (str[i] == 'c')
		i = ft_putchar(va_arg(args, int));
	else if (str[i] == 's')
		i = ft_putstr(va_arg(args, char *));
	else if (str[i] == 'd')
		i = ft_putnbr(va_arg(args, int));
	else if (str[i] == 'i')
		i = ft_putnbr(va_arg(args, int));
	else if (str[i] == 'u')
		i = ft_putnbr_base(va_arg(args, unsigned int), "0123456789");
	else if (str[i] == 'x')
		i = ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (str[i] == 'X')
		i = ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	else if (str[i] == 'p')
		i = ft_print_memory(va_arg(args, unsigned long long int));
	return (i);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		num_args;
	int		i;
	int		ret;

	num_args = ft_strlen(str);
	va_start(args, str);
	i = 0;
	ret = 0;
	while (i < num_args)
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			i++;
			ret += ft_parse(args, i, str);
		}
		else
			ret += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
