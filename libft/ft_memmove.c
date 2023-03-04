/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:17:50 by elevy             #+#    #+#             */
/*   Updated: 2022/11/11 19:53:40 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*srcc;
	char	*destc;
	size_t	i;

	i = -1;
	srcc = (char *)src;
	destc = (char *)dest;
	if (!destc || !srcc)
		return (0);
	if (srcc < destc)
		while ((int)--n >= 0)
			*(destc + n) = *(srcc + n);
	else
		while (++i < n)
			*(destc + i) = *(srcc + i);
	return (dest);
}
