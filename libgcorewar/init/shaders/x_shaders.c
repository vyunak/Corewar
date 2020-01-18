/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_shaders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:22:58 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 14:23:00 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

GLchar const	*get_x_shader_vert(void)
{
	return ((GLchar const *const)
	"#version 410 core\n"
	"\n"
	"layout (location = 0) in vec2   position;\n"
	"\n"
	"layout (location = 1) in vec2   tex;\n"
	"\n"
	"uniform mat4                    model;\n"
	"\n"
	"out vec2                        texture_coords;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    gl_Position = model * vec4(position, 0.0f, 1.0f);\n"
	"    texture_coords = tex;\n"
	"}");
}

GLchar const	*get_x_shader_frag(void)
{
	return ((GLchar const *const)
	"#version 410 core\n"
	"\n"
	"in  vec2			texture_coords;\n"
	"\n"
	"out vec4			color;\n"
	"\n"
	"uniform sampler2D	Texture;\n"
	"\n"
	"uniform vec4		ourcolor;\n"
	"\n"
	"void main()\n"
	"{\n"
	"	vec4 res = texture(Texture, texture_coords);"
	"	color = vec4(res.xyz + ourcolor.xyz, res.w * ourcolor.w);\n"
	"}");
}
