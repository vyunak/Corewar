/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_shaders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:51:29 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 13:51:30 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

GLchar const	*get_frame_shader_vert(void)
{
	return ((GLchar const *const)
	"#version 410 core\n"
	"\n"
	"layout (location = 0) in vec2   position;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    gl_Position = vec4(position, 0.999999f, 1.0f);\n"
	"}");
}

GLchar const	*get_frame_shader_frag(void)
{
	return ((GLchar const *const)
	"#version 410 core\n"
	"\n"
	"out vec4    	color;\n"
	"\n"
	"uniform vec4	ourcolor;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    color = ourcolor;\n"
	"}");
}
