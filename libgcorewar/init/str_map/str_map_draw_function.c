/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_map_draw_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:45:13 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 14:45:14 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	*str_map_draw_function(t_string const *const restrict string,
														void *const param)
{
	(void)param;
	if (!string->active)
		return ((void*)0);
	glBindTexture(GL_TEXTURE_2D, string->texture);
	glBindVertexArray(string->vao);
	glUniform3f(glGetUniformLocation(g_lgs_string_shader_program, "model"),
			string->position.x, string->position.y, string->position.z);
	glUniform4f(glGetUniformLocation(g_lgs_string_shader_program, "user_color"),
			string->color.x, string->color.y, string->color.z, g_map_opacity);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	return (0);
}
