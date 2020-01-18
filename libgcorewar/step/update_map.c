/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:35:34 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:35:34 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	non_update_map(unsigned char const *const map,
						unsigned char const *const owner)
{
	size_t i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (map[i] != g_map[i])
		{
			g_map[i] = map[i];
			if (owner[i])
				g_str_map[i]->color = g_str_champions[owner[i] - 1]->color;
			else
				g_str_map[i]->color = vec4(0.8f, 0.8f, 0.8f, 1.0f);
		}
		i++;
	}
}

void	update_map(unsigned char const *const map,
					unsigned char const *const owner)
{
	size_t	i;
	char	tmp[3];

	i = 0;
	while (i < MEM_SIZE)
	{
		if (map[i] != g_map[i])
		{
			g_map[i] = map[i];
			my_base(g_map[i], tmp);
			string_update_nospace(g_str_map[i], tmp, g_w_width, g_w_height);
		}
		if (owner[i])
			(g_str_map[i])->color = g_str_champions[owner[i] - 1]->color;
		else
			(g_str_map[i])->color = vec4(0.8f, 0.8f, 0.8f, 1.0f);
		i++;
	}
}
