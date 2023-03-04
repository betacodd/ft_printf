/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:19:42 by elevy             #+#    #+#             */
/*   Updated: 2022/11/17 16:09:24 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_all(char	**tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i++] != 0)
		free(tab[i]);
	return ;
}	

static int	ft_count_words(char const *s, char c)
{
	int	res;
	int	i;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			res++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (res);
}

static char	*ft_make_word(char **tab, char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word = malloc (i + 1);
	if (!word)
	{
		free_all(tab);
		return (NULL);
	}
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		wlen;
	int		i;

	wlen = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (wlen + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (*s && i < wlen)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			tab[i] = ft_make_word(tab, s, c);
			if (!tab[i])
				return (NULL);
			s = s + ft_strlen(tab[i++]);
		}
		while (*s && *s != c)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
