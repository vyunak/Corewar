/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid&parse_2_arv.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:51:07 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:51:27 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int				next_step_for_valid(char *line)
{
	char		**str;
	t_while		*tmp;

	str = ft_strsplit(&line[g_data.x], SEPARATOR_CHAR);
	g_data.d = ft_arrlab(str);
	(g_data.d == 0 || g_data.d > 3) ? vy_free_arr(&str) : 0;
	if (g_data.d == 0 || g_data.d > 3)
		return (print_error("number of arguments!"));
	tmp = g_data.list;
	while (tmp->next)
		tmp = tmp->next;
	(tmp->oper) ? create_new_oper(&tmp) : 0;
	if (valid_argv(&str) == 0)
	{
		vy_free_arr(&str);
		return (print_error(line));
	}
	tmp->oper = (t_oper*)malloc(sizeof(t_oper));
	ft_bzero(&*tmp->oper, sizeof(t_oper));
	tmp->oper->name = ft_strndup(line, g_data.i, g_data.x - 1);
	tmp->oper->num = g_data.h;
	tmp->oper->av1 = write_arg(&str[0]);
	(g_data.d > 1) ? tmp->oper->av2 = write_arg(&str[1]) : 0;
	(g_data.d > 2) ? tmp->oper->av3 = write_arg(&str[2]) : 0;
	return (vy_free_arr(&str));
}

void			parse_op(char *line)
{
	g_data.x = 0;
	g_data.i = 0;
	while (white_space(line[g_data.i]))
		g_data.i++;
	g_data.x = g_data.i;
	if ((g_data.o = len_comm(&line[g_data.i])) == -1)
		print_error("number of arguments!");
	while (ft_islabel(line[g_data.x]))
		g_data.x++;
	if ((g_data.h = command_check(line)) >= 0)
	{
		if (ft_strlen(line) == 0)
			return ;
		next_step_for_valid(line);
	}
	else
		print_error("inccorect operation!");
}

int				check_is_set(t_marks *mk, char *str)
{
	while (mk)
	{
		if (ft_strcmp(mk->mark, str) == 0)
			return (1);
		mk = mk->next;
	}
	return (0);
}

void			create_new_mark(t_while **tmp)
{
	(*tmp)->next = (t_while*)malloc(sizeof(t_while));
	ft_bzero(&*(*tmp)->next, sizeof(t_while));
	(*tmp) = (*tmp)->next;
}

void			write_mark(char *str)
{
	t_while		*tmp;
	t_marks		*mk;

	tmp = g_data.list;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->oper)
		create_new_mark(&tmp);
	if (tmp->marks)
	{
		mk = tmp->marks;
		if (check_is_set(mk, str))
			return (free(str));
		while (mk->next)
			mk = mk->next;
		mk->next = (t_marks*)malloc(sizeof(t_marks));
		ft_bzero(&(*mk->next), sizeof(t_marks));
		mk->next->mark = str;
	}
	else
	{
		tmp->marks = (t_marks*)malloc(sizeof(t_marks));
		ft_bzero(&(*tmp->marks), sizeof(t_marks));
		tmp->marks->mark = str;
	}
}
