/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:18:02 by elevy             #+#    #+#             */
/*   Updated: 2022/12/21 14:38:00 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	arg_size(unsigned long arg)
{
	int	count;

	count = 0;
	if (arg == 0)
		return (1);
	while (arg > 0)
	{
		count++;
		arg = arg / 16;
	}
	return (count);
}

int	ft_minhexa(unsigned int arg)
{
	char	*base;

	base = "0123456789abcdef";
	if (arg > 0 && arg <= 15)
	{
		ft_putchar(base[arg]);
	}
	else if (arg == 0)
		ft_putchar('0');
	else
	{
		ft_minhexa(arg / 16);
		ft_minhexa(arg % 16);
	}
	return (arg_size((unsigned long)arg));
}
