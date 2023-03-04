/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:50:55 by elevy             #+#    #+#             */
/*   Updated: 2022/12/21 12:10:23 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr(int nb)
{
	int	num;

	num = 0;
	if (nb == -2147483648)
	{
		num += ft_putchar('-');
		num += ft_putchar('2');
		nb = 147483648;
	}
	if (nb < 0)
	{
		nb = -nb;
		num += ft_putchar ('-');
	}
	if (nb > 9)
	{
		num += ft_putnbr(nb / 10);
		num += ft_putnbr(nb % 10);
	}
	else
		num += ft_putchar(nb + '0');
	return (num);
}
