/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 19:13:45 by seozcan           #+#    #+#             */
/*   Updated: 2021/12/13 20:01:29 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <string.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putnbr(int nb);
int		ft_putnbr_base(unsigned long long int nb, char *base);
int		ft_print_memory(unsigned long long int nb);
int		ft_parse(va_list args, int num_args, const char *str);
int		ft_putstr(char *s);
int		ft_putchar(char c);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

#endif
