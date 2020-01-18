/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_list_update_module.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:16:05 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:16:06 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	create_elem(t_carriage const *const restrict carriage)
{
	t_carr_lst	*tmp;

	tmp = (t_carr_lst*)malloc(sizeof(t_carr_lst));
	if (!tmp)
		exit_error("malloc error");
	tmp->id = carriage->id;
	tmp->alive = 1;
	tmp->player = carriage->player;
	tmp->position = carriage->posit;
	tmp->prev_position = carriage->posit;
	tmp->x = g_str_map[tmp->position]->position.x;
	tmp->y = g_str_map[tmp->position]->position.y;
	g_counts[tmp->player - 1]++;
	carriage_list_add(&g_carriage_lst, tmp);
}

void	free_carriage(t_carriage *restrict del)
{
	del->prev->next = del->next;
	if (del->next)
		del->next->prev = del->prev;
	free(del);
}

void	free_first_carriage(t_carriage **restrict elem)
{
	t_carriage *const tmp = *elem;

	*elem = (*elem)->next;
	if (*elem)
		(*elem)->prev = 0;
	free(tmp);
}
