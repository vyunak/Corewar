/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:50:49 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 14:50:50 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static size_t	get_max_width(void)
{
	size_t	nb;
	int		res;

	nb = 0;
	res = 0;
	while (nb < (size_t)g_number_of_champions)
	{
		if (g_str_champions[nb]->image_width > res)
			res = g_str_champions[nb]->image_width;
		nb++;
	}
	return (res);
}

void			create_x(void)
{
	t_mat4	matrix;

	create_x_shader_program();
	matrix = mat4_translate(vec3(
		1.0f - M_W / 2 - (0.25 * STR_CH_FS + X_D + 0.5f * get_max_width())
				/ g_w_width * 2,
		g_str_champions[0]->position.y, 0.0f));
	g_x.picture = create_picture_x(STR_CH_FS * 0.5);
	create_x_vao(STR_CH_FS * 0.5);
	g_x.model = matrix;
	g_x.draw = 0;
	g_x.init = 1;
	g_x.color = g_str_champions[0]->color;
	g_x.color.w = 0;
	g_x.position = 1;
}
