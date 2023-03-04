/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:24:43 by elevy             #+#    #+#             */
/*   Updated: 2022/11/19 10:47:15 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*tab;
	unsigned int	n;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	n = ft_strlen(s);
	if (start >= n)
	{
		tab = ft_calloc(1, 1);
		return (tab);
	}
	if (len <= n - start)
		tab = malloc (len + 1);
	else
		tab = malloc (n - start + 1);
	if (!tab)
		return (NULL);
	while (start < n && s[start] && len-- > 0)
		tab[i++] = (char)(s[start++]);
	tab[i] = 0;
	return (tab);
}
