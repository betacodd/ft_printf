/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elevy <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:14:32 by elevy             #+#    #+#             */
/*   Updated: 2022/11/09 14:18:40 by elevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*temp;

	if (!lst || !del)
		return (NULL);
	dest = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			while (dest)
			{
				temp = dest->next;
				ft_lstdelone(dest, del);
				dest = temp;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&dest, temp);
		lst = lst->next;
	}
	return (dest);
}	
