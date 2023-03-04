/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:22:16 by elevy             #+#    #+#             */
/*   Updated: 2022/11/12 15:29:04 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (size != 0 && i < size - 1 && src[i])
	{
		dst[i] = src[i];
		++i;
	}
	if (i < size)
		dst[i] = 0;
	while (src[i])
		++i;
	return (i);
}
