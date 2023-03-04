/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_majhexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 15:20:03 by elevy             #+#    #+#             */
/*   Updated: 2022/12/21 14:52:58 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_majhexa(unsigned int arg)
{
	int		num;
	char	*base;

	num = 0;
	base = "0123456789ABCDEF";
	if (arg >= 16)
	{
		num += ft_majhexa(arg / 16);
		num += ft_majhexa(arg % 16);
	}
	else
		num += ft_putchar(base[arg]);
	return (arg_size((unsigned long)arg));
}
