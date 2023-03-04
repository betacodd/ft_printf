/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:24:19 by elevy             #+#    #+#             */
/*   Updated: 2022/11/11 13:24:21 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_alloc(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && ft_is_set(set, s1[i]))
		i++;
	while (len > i && ft_is_set(set, s1[len - 1]))
		len--;
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	start;

	str = (char *)malloc(ft_count_alloc(s1, set) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = ft_strlen(s1);
	while (s1[i] && ft_is_set(set, s1[i]))
		i++;
	while (j > i && ft_is_set(set, s1[j - 1]))
		j--;
	start = 0;
	while (i < j)
		str[start++] = s1[i++];
	str[start] = 0;
	return (str);
}
