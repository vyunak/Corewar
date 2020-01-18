/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:52:01 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:52:02 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	lines_draw(void)
{
	int i;

	i = 0;
	while (i < 4 + g_number_of_champions)
	{
		glUseProgram(g_frame_shader_program);
		glBindVertexArray(g_lines[i].vao);
		glUniform4f(glGetUniformLocation(g_frame_shader_program, "ourcolor"),
			g_lines[i].color.x, g_lines[i].color.y,
			g_lines[i].color.z, g_lines[i].color.w);
		glDrawArrays(GL_LINES, 0, 2);
		i++;
	}
	glBindVertexArray(0);
}
