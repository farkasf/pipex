/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:07:05 by ffarkas           #+#    #+#             */
/*   Updated: 2023/01/23 08:24:45 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_new;
	t_list	*node;

	if (lst == 0)
		return (NULL);
	lst_new = NULL;
	while (lst)
	{
		node = ft_lstnew((*f)(lst->content));
		if (node == 0)
		{
			ft_lstclear(&lst_new, del);
			return (NULL);
		}
		ft_lstadd_back(&lst_new, node);
		lst = lst->next;
	}
	return (lst_new);
}
