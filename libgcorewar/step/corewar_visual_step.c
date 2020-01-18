/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visual_step.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:22:31 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:22:32 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static void	carriages_counters_update(void)
{
	char	*str;
	size_t	i;

	i = 0;
	while (i < (size_t)g_number_of_champions)
	{
		str = my_uitoa(g_counts[i]);
		string_update(g_counters[i], str, g_w_width, g_w_height);
		free(str);
		i++;
	}
}

static void	cyc_to_die_update(t_arena const *const restrict arena)
{
	char const	*str;

	if (arena->cydeath == g_last_cyc_to_die)
		return ;
	if (arena->cydeath >= 0)
		str = my_uitoa(arena->cydeath);
	else
		str = my_uitoa(0);
	if (!str)
		exit_error("my_uitoa error");
	string_update(g_str_cyc_to_die, str, g_w_width, g_w_height);
	free((void*)str);
	g_last_cyc_to_die = arena->cydeath;
}

void		corewar_visual_step(t_arena const *const restrict arena,
								t_carriage **const restrict carriages)
{
	static uintmax_t	step_nb = 0;
	char const			*str;

	step_nb++;
	str = my_uitoa(step_nb);
	if (!str)
		exit_error("my_uitoa error");
	g_update_map(arena->cell, arena->owner);
	cyc_to_die_update(arena);
	string_update(g_str_step_counter, str, g_w_width, g_w_height);
	free((void*)str);
	carriage_list_update(carriages);
	carriages_counters_update();
	step_draw(arena->lastlive);
}
