/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame_shader_program.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:21:34 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 13:21:35 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>
#include <unistd.h>

static GLuint	create_frame_shader_vertex(void)
{
	char				log[512];
	GLint				success;
	const GLuint		vshader = glCreateShader(GL_VERTEX_SHADER);
	GLchar const *const	v_shader_str = get_frame_shader_vert();

	glShaderSource(vshader, 1, &v_shader_str, 0);
	glCompileShader(vshader);
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vshader, 512, NULL, log);
		exit_error(log);
	}
	return (vshader);
}

static GLuint	create_frame_shader_fragment(void)
{
	char				log[512];
	GLint				success;
	const GLuint		fshader = glCreateShader(GL_FRAGMENT_SHADER);
	GLchar const *const	f_shader_str = get_frame_shader_frag();

	glShaderSource(fshader, 1, &f_shader_str, 0);
	glCompileShader(fshader);
	glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fshader, 512, NULL, log);
		exit_error(log);
	}
	return (fshader);
}

void			create_frame_shader_program(void)
{
	const GLuint		vshader = create_frame_shader_vertex();
	const GLuint		fshader = create_frame_shader_fragment();
	char				log[512];
	GLint				success;

	g_frame_shader_program = glCreateProgram();
	glAttachShader(g_frame_shader_program, vshader);
	glAttachShader(g_frame_shader_program, fshader);
	glLinkProgram(g_frame_shader_program);
	glGetProgramiv(g_frame_shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(g_frame_shader_program, 512, NULL, log);
		exit_error(log);
	}
	glDeleteShader(vshader);
	glDeleteShader(fshader);
}
