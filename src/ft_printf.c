/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:25:03 by elevy             #+#    #+#             */
/*   Updated: 2022/12/24 15:35:47 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_flags(va_list ap, char c)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, unsigned int)));
	if (c == 's')
		return (ft_putstr(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_voidhexa(va_arg(ap, unsigned long)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_putnbr_uns(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_minhexa(va_arg(ap, unsigned int)));
	if (c == 'X')
		return (ft_majhexa(va_arg(ap, unsigned int)));
	if (c == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		val;
	int		i;

	i = 0;
	if (str == 0)
		return (0);
	va_start(ap, str);
	val = 0;
	while (str[i])
	{
		if (str[i] != '%')
			val += ft_putchar(str[i]);
		else
		{
			val += ft_flags(ap, str[i + 1]);
			i++;
		}
		i++;
	}
	return (val);
}
