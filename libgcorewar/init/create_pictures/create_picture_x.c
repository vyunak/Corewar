/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_picture_x.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:19:14 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 13:19:15 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>
#include <unistd.h>

static void				draw_line_1(unsigned char *const restrict picture,
															const size_t width)
{
	size_t	i;

	i = 0;
	while (i < width)
	{
		picture[(i * width + i) * 4 + 3] = 255;
		if (i < width - 1)
		{
			picture[(i * width + i + 1) * 4 + 3] = 255;
			picture[((i + 1) * width + i) * 4 + 3] = 255;
			picture[(i * width + i + 2) * 4 + 3] = 255;
			picture[((i + 2) * width + i) * 4 + 3] = 255;
		}
		i++;
	}
}

static void				draw_line_2(unsigned char *const restrict picture,
															const size_t width)
{
	size_t i;
	size_t j;

	i = width - 1;
	j = 0;
	while (j < width)
	{
		picture[(i * width + j) * 4 + 3] = 255;
		if (j < width - 1)
		{
			picture[(i * width + j + 1) * 4 + 3] = 255;
			picture[((i - 1) * width + j) * 4 + 3] = 255;
			picture[(i * width + j + 2) * 4 + 3] = 255;
			picture[((i - 2) * width + j) * 4 + 3] = 255;
		}
		i--;
		j++;
	}
}

static unsigned char	*create_picture_array(const size_t width)
{
	unsigned char *restrict	picture;

	if (!(picture = (uint8_t*)malloc(sizeof(uint8_t) * width * width * 4)))
		exit_error("create_picture malloc error");
	my_memset(picture, 0, sizeof(unsigned char) * width * width * 4);
	draw_line_1(picture, width);
	draw_line_2(picture, width);
	return (picture);
}

GLuint					create_picture_x(const size_t width)
{
	unsigned char const *restrict	picture;
	GLuint							texture;
	float const						border_color[] = { 0.0f, 0.0f, 0.0f, 0.0f };

	picture = create_picture_array(width);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
												GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, width, 0, GL_RGBA,
												GL_UNSIGNED_BYTE, picture);
	glGenerateMipmap(GL_TEXTURE_2D);
	free((void*)picture);
	glBindTexture(GL_TEXTURE_2D, 0);
	return (texture);
}
