/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:50:24 by seozcan           #+#    #+#             */
/*   Updated: 2022/01/14 10:50:47 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_putnbr_base(unsigned long long int nb, char *base)
{
	unsigned long long int	baselen;

	baselen = ft_strlen(base);
	if (nb >= baselen)
		ft_putnbr_base(nb / baselen, base);
	ft_putchar_fd(base[nb % baselen], 1);
}
