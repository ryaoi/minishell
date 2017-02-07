/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryaoi <ryaoi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 17:34:43 by ryaoi             #+#    #+#             */
/*   Updated: 2016/11/05 16:26:11 by ryaoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*stock;
	t_list	*next;

	new = NULL;
	if (lst)
	{
		new = (*f)(lst);
		stock = new;
		lst = lst->next;
		while (lst)
		{
			next = (*f)(lst);
			stock->next = next;
			stock = next;
			lst = lst->next;
		}
		stock->next = NULL;
	}
	return (new);
}
