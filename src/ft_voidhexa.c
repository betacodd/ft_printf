/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidhexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 12:32:11 by elevy             #+#    #+#             */
/*   Updated: 2022/12/21 14:38:48 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_voidhexa(unsigned long long addr)
{
	char	buf[32];
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	if (addr == 0)
	{
		cnt += ft_putstr ("(nil)");
		return (cnt);
	}
	while (addr != 0)
	{
		buf[i++] = "0123456789abcdef"[addr % 16];
		addr /= 16;
	}
	buf[i++] = 'x';
	buf[i++] = '0';
	i--;
	while (i >= 0)
		cnt += write(1, &buf[i--], 1);
	return (cnt);
}
