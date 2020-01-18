/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:27:46 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:27:54 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*t;
	t_list		*ls;

	if (!lst || !f)
		return (NULL);
	ls = f(lst);
	t = ls;
	while (lst->next)
	{
		lst = lst->next;
		ls->next = f(lst);
		if (!(ls->next))
		{
			free(ls->next);
			return (NULL);
		}
		ls = ls->next;
	}
	return (t);
}
