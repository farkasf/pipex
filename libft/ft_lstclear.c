/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffarkas <ffarkas@student.42prague.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 08:09:47 by ffarkas           #+#    #+#             */
/*   Updated: 2023/01/23 08:24:30 by ffarkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*pult;

	if (*lst == 0)
		return ;
	while (*lst)
	{
		pult = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = pult;
	}
	*lst = NULL;
}
