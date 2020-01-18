/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_picture_carriage.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:16:48 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 13:16:50 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

size_t					math_length(void)
{
	const size_t	frame_length = 3;

	g_carriage_height += ((frame_length + 1) * 2);
	g_carriage_width += ((frame_length + 1) * 2);
	return (frame_length);
}

static unsigned char	*create_picture_array(const size_t width,
					const size_t height, const size_t frame_length)
{
	unsigned char *restrict	picture;
	size_t					i;
	size_t					j;

	if (!(picture = (uint8_t*)malloc(sizeof(uint8_t) * width * height * 4)))
		exit_error("create_picture malloc error");
	my_memset(picture, 0, sizeof(unsigned char) * width * height * 4);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i < frame_length || i >= height - frame_length)
			|| (j < frame_length || j >= width - frame_length))
				picture[(i * width + j) * 4 + 3] = 255;
			j++;
		}
		i++;
	}
	return (picture);
}

GLuint					create_picture_carriege(const size_t width,
					const size_t height, const size_t frame_length)
{
	unsigned char const	*restrict	picture;
	GLuint							texture;
	float const						border_color[] = { 0.0f, 0.0f, 0.0f, 0.0f };

	picture = create_picture_array(width, height, frame_length);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
												GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA,
												GL_UNSIGNED_BYTE, picture);
	glGenerateMipmap(GL_TEXTURE_2D);
	free((void*)picture);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (texture);
}
