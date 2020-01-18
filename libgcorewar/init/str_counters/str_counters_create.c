/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_counters_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:35:42 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 14:35:43 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	str_counters_create(void)
{
	const float	d_x = M_W / (g_number_of_champions + 1);
	int			i;

	i = 0;
	g_counters = (t_string**)malloc(sizeof(t_string*) * g_number_of_champions);
	if (!g_counts || !g_counters)
		exit_error("malloc error");
	while (i < g_number_of_champions)
	{
		g_counters[i] = string_get_elem(string_create("1",
				vec3(1.0f - M_W + d_x * (i + 1),
				S_3 - (S_3 - S_4 - S_H) / 1.5, 0.0f),
				STR_CO_FS, vec4(1.0f, 1.0f, 1.0f, 0.0f), g_window));
		create_line_vao(4 + i, g_counters[i]->position.x,
			g_counters[i]->position.y
			- (float)(g_counters[i]->image_height + CO_LD) / g_w_height, CO_LW);
		g_lines[4 + i].color = g_str_champions[i]->color;
		i++;
	}
}
