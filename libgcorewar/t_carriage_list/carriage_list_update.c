/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_list_update.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:12:38 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:12:39 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>
#include <stdlib.h>

static t_carr_lst	*find_elem(const unsigned int id)
{
	t_carr_lst	*tmp;

	tmp = g_carriage_lst;
	while (tmp && tmp->id != id)
		tmp = tmp->next;
	return (tmp);
}

static void			elem_update(t_carr_lst *tmp, t_carriage *elem)
{
	tmp->prev_position = tmp->position;
	tmp->position = elem->posit;
	tmp->x = g_str_map[tmp->position]->position.x;
	tmp->y = g_str_map[tmp->position]->position.y;
}

void				carriage_list_update(t_carriage **restrict carriages)
{
	t_carr_lst *restrict	tmp;
	t_carriage				*elem;

	elem = (t_carriage*)*carriages;
	while (elem)
	{
		tmp = find_elem(elem->id);
		if (!tmp)
			create_elem(elem);
		else if (!elem->alive)
		{
			tmp->alive = 0;
			if (elem == *carriages)
			{
				elem = elem->next;
				free_first_carriage(carriages);
				continue;
			}
			free_carriage(elem);
			g_counts[tmp->player - 1]--;
		}
		else
			elem_update(tmp, elem);
		elem = elem->next;
	}
}
