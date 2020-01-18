/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_list_del.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:12:34 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:12:35 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	carriage_list_del(t_carr_lst **const restrict lst,
							t_carr_lst *const elem)
{
	if (*lst == elem)
	{
		*lst = (*lst)->next;
		if (*lst)
			(*lst)->prev = 0;
		free(elem);
		return ;
	}
	elem->prev->next = elem->next;
	if (elem->next)
		elem->next->prev = elem->prev;
	free(elem);
}
