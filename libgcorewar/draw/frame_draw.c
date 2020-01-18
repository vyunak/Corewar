/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:51:43 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:51:44 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	frames_draw(void)
{
	int i;

	i = 0;
	while (i < FR_C)
	{
		glUseProgram(g_frame_shader_program);
		glBindVertexArray(g_v_frame[i].vao);
		glUniform4f(glGetUniformLocation(g_frame_shader_program, "ourcolor"),
			g_v_frame[i].color.x, g_v_frame[i].color.y,
			g_v_frame[i].color.z, g_v_frame[i].color.w);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		i++;
	}
	glBindVertexArray(0);
}
