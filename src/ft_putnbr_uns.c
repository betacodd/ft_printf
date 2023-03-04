/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:07:21 by elevy             #+#    #+#             */
/*   Updated: 2022/12/21 14:03:33 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnbr_uns(unsigned int nb)
{
	int	num;

	num = 0;
	if (nb > 9)
	{
		num += ft_putnbr_uns(nb / 10);
		num += ft_putnbr_uns(nb % 10);
	}
	else
		num += ft_putchar(nb + '0');
	return (num);
}
