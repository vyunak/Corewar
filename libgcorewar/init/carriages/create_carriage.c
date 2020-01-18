/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_carriage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 12:55:51 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 12:55:52 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static void	set_carriage_height(void)
{
	FT_Glyph glyph;

	glyph = 0;
	FT_Load_Char(g_ftface, 'X', FT_LOAD_RENDER);
	FT_Get_Glyph(g_ftface->glyph, &glyph);
	g_carriage_height = ((FT_BitmapGlyph)glyph)->bitmap.rows;
	FT_Done_Glyph(glyph);
}

void		create_carriage(void)
{
	size_t	frame_length;

	set_carriage_height();
	frame_length = math_length();
	g_v_carriage.picture =
			create_picture_carriege(g_carriage_width, g_carriage_height,
														frame_length);
	create_carriage_vao(g_carriage_width, g_carriage_height);
	g_v_carriage.model = mat4_init();
}
