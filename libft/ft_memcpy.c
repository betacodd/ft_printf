/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:17:35 by elevy             #+#    #+#             */
/*   Updated: 2022/11/11 13:17:37 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*src2;
	unsigned char	*dest2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (src2 && n-- > 0)
	{
		*dest2++ = *src2++;
	}
	return (dest);
}
