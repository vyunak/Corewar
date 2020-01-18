/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:43:22 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:51:59 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int				get_name_p2(int i[2], char *ln)
{
	i[1] = i[0] + 1;
	while (ln[i[1]] != '"' && ln[i[1]] != '\0')
		i[1]++;
	if (ln[i[1]] != '"' || (ln[i[1] + 1] != '\0' && ln[i[1] + 1] != '\n'
		&& !white_space(ln[i[1] + 1]) && ln[i[1] + 1] != COMMENT_CHAR &&
		ln[i[1] + 1] != ALT_COMMENT_CHAR) ||
		st_end(&ln[i[1]]) == 0 || i[1] - i[0] > PROG_NAME_LENGTH)
		return (print_error("inccorect name!"));
	g_data.cp_name = ft_strndup(ln, i[0] + 1, i[1] - 1);
	g_data.name = 1;
	return (1);
}

int				get_comment_p2(int i[2], char *ln)
{
	i[1] = i[0] + 1;
	while (ln[i[1]] != '"' && ln[i[1]] != '\0')
		i[1]++;
	if (ln[i[1]] != '"' || (ln[i[1] + 1] != '\0' && ln[i[1] + 1] != '\n'
		&& !white_space(ln[i[1] + 1]) && ln[i[1] + 1] != COMMENT_CHAR &&
		ln[i[1] + 1] != ALT_COMMENT_CHAR) ||
		st_end(&ln[i[1]]) == 0 || i[1] - i[0] > COMMENT_LENGTH)
		return (print_error("inccorect comment!"));
	g_data.cp_comment = ft_strndup(ln, i[0] + 1, i[1] - 1);
	g_data.comment = 1;
	return (1);
}

void			all_free_while(t_while *ton2)
{
	t_marks		*mar;
	t_marks		*mar2;

	mar = ton2->marks;
	while (mar)
	{
		mar2 = mar;
		(mar2->mark) ? free(mar2->mark) : 0;
		mar = mar->next;
		(mar2) ? free(mar2) : 0;
	}
	if (ton2->oper)
	{
		(ton2->oper->name) ? free(ton2->oper->name) : 0;
		(ton2->oper->av1) ? free(ton2->oper->av1) : 0;
		(ton2->oper->av2) ? free(ton2->oper->av2) : 0;
		(ton2->oper->av3) ? free(ton2->oper->av3) : 0;
		free(ton2->oper);
	}
}

void			all_free(void)
{
	t_while		*ton;
	t_while		*ton2;

	ton = g_data.list;
	while (ton)
	{
		ton2 = ton;
		ton = ton->next;
		all_free_while(ton2);
		(ton2) ? free(ton2) : 0;
	}
	(g_data.cp_name) ? free(g_data.cp_name) : 0;
	(g_data.cp_comment) ? free(g_data.cp_comment) : 0;
	(g_data.num) ? free(g_data.num) : 0;
}

void			file_struct_malloc(t_files **file)
{
	*file = (t_files*)malloc(sizeof(t_files));
	ft_bzero(&**file, sizeof(t_files));
}
