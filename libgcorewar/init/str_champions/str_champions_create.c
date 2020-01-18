/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_champions_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:30:11 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 14:30:12 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static t_vec4	*set_colors(void)
{
	t_vec4 *const restrict vectors = (t_vec4*)malloc(sizeof(t_vec4) * 4);

	vectors[0] = vec4(0.850980392156863f, 0.325490196078431f,
							0.309803921568627f, 1.0f);
	vectors[1] = vec4(1.0f, 0.654901960784314f, 0.0f, 1.0f);
	vectors[2] = vec4(0.36078431372549f, 0.72156862745098f,
							0.36078431372549f, 1.0f);
	vectors[3] = vec4(0.258823529411765f, 0.545098039215686f,
							0.792156862745098f, 1.0f);
	return (vectors);
}

static void		create_string(const size_t i,
		t_vec4 const *const restrict colors, const float y, char *name)
{
	char const *tmp;

	tmp = 0;
	if (ft_strlen(name) > STR_CH_ML)
	{
		tmp = name;
		name = (char*)malloc(sizeof(char) * STR_CH_ML + 1);
		if (!name)
			exit_error("create string malloc error");
		my_strncat(name, tmp, STR_CH_ML - 3);
		my_memset(name + STR_CH_ML - 3, '.', 3);
		name[STR_CH_ML] = 0;
	}
	g_str_champions[i] = string_get_elem(string_create_nospace(name,
		vec3(1.0f - M_W / 2, y, 0.0f),
		STR_CH_FS, colors[i % 4], g_window));
	g_str_champions[i]->active = 0;
	if (tmp)
		free(name);
}

void			str_champions_create(t_champ const **const restrict champions)
{
	size_t							i;
	t_vec4 const *const restrict	colors = set_colors();
	float							dy;
	float							y;

	dy = (float)(STR_CH_FS) / g_w_height + STR_CH_SS;
	y = S_2 - STR_CH_SS
		- ((float)(STR_CH_FS) / g_w_height / 2);
	g_number_of_champions = 0;
	while (champions[(int)g_number_of_champions])
		g_number_of_champions++;
	g_str_champions = (t_string**)malloc(
								sizeof(t_string*) * g_number_of_champions);
	if (!g_str_champions || !colors)
		exit_error("str_champions malloc error");
	i = 0;
	while (i < (size_t)g_number_of_champions)
	{
		create_string(i, colors, y, champions[i]->name);
		y -= dy;
		i++;
	}
	free((void*)colors);
}
