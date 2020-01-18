/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_step_carriage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:33:45 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:33:47 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static void	init_carriage(void)
{
	t_carr_lst	*elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
			elem->prev_x = elem->x;
			elem->prev_y = elem->y;
		}
		elem = elem->next;
	}
}

static void	complete_carriage(void)
{
	t_carr_lst	*elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
			elem->x = g_str_map[elem->position]->position.x;
			elem->y = g_str_map[elem->position]->position.y;
		}
		else if (!elem->alive)
			carriage_list_del(&g_carriage_lst, elem);
		elem = elem->next;
	}
}

static void	step_carriage(const double start, const double time)
{
	t_carr_lst	*elem;

	elem = g_carriage_lst;
	while (elem)
	{
		if (elem->alive && elem->prev_position != elem->position)
		{
			elem->x = g_str_map[elem->prev_position]->position.x
				+ ((g_str_map[elem->position]->position.x
				- g_str_map[elem->prev_position]->position.x) / g_step_time
				* (time - start));
			elem->y = g_str_map[elem->prev_position]->position.y
				+ ((g_str_map[elem->position]->position.y
				- g_str_map[elem->prev_position]->position.y) / g_step_time
				* (time - start));
		}
		elem = elem->next;
	}
}

char		str_step_carriage(const char init, const double time)
{
	static double	start;

	if (init)
	{
		init_carriage();
		start = time;
		return (0);
	}
	else if (time - start > g_step_time)
	{
		complete_carriage();
		return (1);
	}
	step_carriage(start, time);
	return (0);
}
