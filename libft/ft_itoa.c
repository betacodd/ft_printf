/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:15:21 by elevy             #+#    #+#             */
/*   Updated: 2022/11/11 13:15:24 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(long n)
{
	int	res;

	res = 0;
	if (n <= 0)
	{
		res++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*tab;
	int		len;
	long	nb;

	nb = n;
	len = ft_numlen(nb);
	tab = malloc (len + 1);
	if (!tab)
		return (NULL);
	tab[len--] = 0;
	if (nb == 0)
		tab[0] = '0';
	if (nb < 0)
	{
		tab[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		tab[len--] = 48 + (nb % 10);
		nb = nb / 10;
	}
	return (tab);
}
