/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:21:53 by elevy             #+#    #+#             */
/*   Updated: 2022/11/12 15:29:39 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0 || !(src))
		return (ft_strlen(src) + size);
	while (dst[i])
		i++;
	while (src[j])
		j++;
	if (size < i)
		return (j + size);
	j += i;
	while (*src && i < (size - 1) && size != 0)
	{
		dst[i] = *src;
		i++;
		src++;
	}
	dst[i] = 0;
	return (j);
}
