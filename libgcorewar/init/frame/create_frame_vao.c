/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_frame_vao.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:21:39 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 13:21:40 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static GLfloat	*create_frame_verts(const t_vec4 verts)
{
	GLfloat *const restrict res = (GLfloat*)malloc(sizeof(GLfloat) * 8);

	if (!res)
	{
		exit_error("malloc error");
		return (0);
	}
	res[0] = verts.x;
	res[1] = verts.z;
	res[2] = verts.x;
	res[3] = verts.w;
	res[4] = verts.y;
	res[5] = verts.z;
	res[6] = verts.y;
	res[7] = verts.w;
	return (res);
}

static GLuint	*create_frame_indices(void)
{
	GLuint *const restrict res = (GLuint*)malloc(sizeof(GLuint) * 6);

	if (!res)
	{
		exit_error("malloc error");
		return (0);
	}
	res[0] = 0;
	res[1] = 1;
	res[2] = 2;
	res[3] = 1;
	res[4] = 2;
	res[5] = 3;
	return (res);
}

void			create_frame_vao(const t_create_frame_vao_args args)
{
	GLfloat const *const restrict	verts = create_frame_verts(args.args);
	GLuint const *const restrict	indices = create_frame_indices();

	glGenBuffers(1, &(args.vao->vbo));
	glGenBuffers(1, &(args.vao->ebo));
	glGenVertexArrays(1, &(args.vao->vao));
	glBindVertexArray(args.vao->vao);
	glBindBuffer(GL_ARRAY_BUFFER, args.vao->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 8, verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, args.vao->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6, indices,
																GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	free((void*)verts);
	free((void*)indices);
}
