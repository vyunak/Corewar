/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_map_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:42:40 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 14:42:42 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static void	module(unsigned char const *const owner, const size_t i)
{
	if (owner[i])
		(g_str_map[i])->color = g_str_champions[owner[i] - 1]->color;
	g_str_map[i]->draw_func = str_map_draw_function;
	if ((int)g_carriage_width < g_str_map[i]->image_width)
		g_carriage_width = g_str_map[i]->image_width;
}

static void	str_map_string_create(const float d_x, const float d_y,
								unsigned char const *const owner)
{
	size_t	i;
	char	tmp[3];
	float	x;
	float	y;

	i = 0;
	x = 0;
	y = 1.0f - d_y - d_y / 2;
	while (i < MEM_SIZE)
	{
		my_base(g_map[i], tmp);
		x += d_x;
		if (i % STR_M_RL == 0)
		{
			x = -1.0f + d_x + d_x / 2;
			if (i > 0)
				y -= d_y;
		}
		g_str_map[i] = string_get_elem(string_create_nospace(tmp,
		vec3(x, y, 0.0f), STR_M_FS, vec4(0.8f, 0.8f, 0.8f, 1.0f), g_window));
		module(owner, i);
		i++;
	}
}

void		str_map_create(unsigned char const *const map,
					unsigned char const *const owner)
{
	size_t i;

	g_map = (unsigned char *)malloc(sizeof(unsigned char) * MEM_SIZE);
	if (!g_map)
		exit_error("str_map malloc error");
	i = 0;
	while (i < MEM_SIZE)
	{
		g_map[i] = map[i];
		i++;
	}
	g_carriage_width = 0;
	g_str_map = (t_string**)malloc(sizeof(t_string*) * (MEM_SIZE + 1));
	str_map_string_create((2.0f - M_W) / (STR_M_RL + 2),
			2.0f / (MEM_SIZE / STR_M_RL + 2), owner);
	g_map_opacity = 0.0f;
}
