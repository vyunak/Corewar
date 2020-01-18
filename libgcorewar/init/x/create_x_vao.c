/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_x_vao.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:52:16 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 14:52:17 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static void		set_verts(t_vec4 *vecs, const int width, const t_mat4 proj)
{
	vecs[0] = mat_vec_4_mult(proj, vec4(
			-(width / 2), width / 2 + width % 2, 1.0f, 1.0f));
	vecs[1] = mat_vec_4_mult(proj, vec4(
			-(width / 2), -(width / 2), 1.0f, 1.0f));
	vecs[2] = mat_vec_4_mult(proj, vec4(
			width / 2 + width % 2, width / 2 + width % 2, 1.0f, 1.0f));
	vecs[3] = mat_vec_4_mult(proj, vec4(
			width / 2 + width % 2, -(width / 2), 1.0f, 1.0f));
}

static void		create_carriage_verts(GLfloat *const res, int width,
												const t_mat4 proj)
{
	t_vec4	vecs[4];

	if (!res)
	{
		exit_error("malloc error");
		return ;
	}
	set_verts(vecs, width, proj);
	res[0] = vecs[1].x;
	res[1] = vecs[1].y;
	res[2] = 0.0f;
	res[3] = 1.0f;
	res[4] = vecs[0].x;
	res[5] = vecs[0].y;
	res[6] = 0.0f;
	res[7] = 0.0f;
	res[8] = vecs[3].x;
	res[9] = vecs[3].y;
	res[10] = 1.0f;
	res[11] = 1.0f;
	res[12] = vecs[2].x;
	res[13] = vecs[2].y;
	res[14] = 1.0f;
	res[15] = 0.0f;
}

static GLuint	*create_carriage_indices(void)
{
	GLuint *const res = (GLuint*)malloc(sizeof(GLuint) * 6);

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

void			create_x_vao(const size_t width)
{
	GLfloat *restrict				verts;
	GLuint const *const restrict	indices = create_carriage_indices();

	verts = (GLfloat*)malloc(sizeof(GLfloat) * 16);
	create_carriage_verts(verts, width, mat4_orthographic(
			-(g_w_width / 2), g_w_width / 2 + g_w_width % 2, -(g_w_height / 2),
			g_w_height / 2 + g_w_height % 2, 0.001f, 100.0f));
	glGenVertexArrays(1, &(g_x.vao));
	glGenBuffers(1, &(g_x.vbo));
	glGenBuffers(1, &(g_x.ebo));
	glBindVertexArray(g_x.vao);
	glBindBuffer(GL_ARRAY_BUFFER, g_x.vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, verts, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, g_x.ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6, indices,
															GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat),
											(GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	free(verts);
	free((void*)indices);
}
