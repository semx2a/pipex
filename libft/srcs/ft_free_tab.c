/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 18:50:06 by seozcan           #+#    #+#             */
/*   Updated: 2022/01/28 18:50:08 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void    ft_free_tab(char **tab, int len)
{
	while (len >= 0)
	{
		free(tab[len]);
		len--;
	}
	free(tab);
}
