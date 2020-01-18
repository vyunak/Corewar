/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_shift.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:01:36 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:01:37 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static void	hide(void)
{
	size_t	i;
	char	*tmp;

	tmp = "XX\0";
	i = 0;
	g_update_map = non_update_map;
	g_carriages_draw = non_carriages_draw;
	while (i < MEM_SIZE)
	{
		string_update_nospace(g_str_map[i], tmp, g_w_width, g_w_height);
		i++;
	}
}

static void	show(void)
{
	size_t	i;
	char	tmp[3];

	i = 0;
	g_update_map = update_map;
	g_carriages_draw = carriages_draw;
	while (i < MEM_SIZE)
	{
		my_base(g_map[i], tmp);
		string_update_nospace(g_str_map[i], tmp, g_w_width, g_w_height);
		i++;
	}
}

void		key_shift(void *args)
{
	(void)args;
	g_hidden = !g_hidden;
	if (!g_hidden)
		show();
	else
		hide();
}
