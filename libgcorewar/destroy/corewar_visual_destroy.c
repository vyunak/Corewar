/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visual_destroy.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:37:42 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:37:50 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static char		*create_tmp_string(t_champ *champion)
{
	char	*str;
	int		i;

	str = (char*)malloc(sizeof(char) * (my_strlen(champion->name) + 13));
	my_strncat(str, "WINNER: ", 8);
	str[8] = champion->id + 48;
	my_strncat(str + 9, ".\"", 2);
	i = 11;
	while (champion->name[i - 11])
	{
		str[i] = champion->name[i - 11];
		i++;
	}
	str[i] = '\"';
	str[i + 1] = 0;
	return (str);
}

static t_string	*create_string(t_champ *champion)
{
	t_string	*res;
	char *const	str = create_tmp_string(champion);

	res = string_get_elem(string_create_nospace(str, vec3(0.0f, 0.0f, 0.0f),
			WI_FS, g_str_champions[champion->id - 1]->color, g_window));
	res->color.w = 0;
	free(str);
	return (res);
}

void			corewar_visual_destroy(t_champ *champion)
{
	g_str_winner = create_string(champion);
	destroy_draw();
	glfwTerminate();
}
