/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:20:47 by elevy             #+#    #+#             */
/*   Updated: 2022/11/12 12:02:59 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	n;

	if (!s)
		return (NULL);
	n = ft_strlen(s);
	new = (char *) malloc (sizeof(*s) * n + 1);
	if (!new)
		return (NULL);
	return (ft_memcpy(new, s, n + 1));
}
