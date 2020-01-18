/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_name_comment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:42:35 by ashypilo          #+#    #+#             */
/*   Updated: 2019/08/21 16:54:27 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static	int	code_argv(char *arg, t_while *head)
{
	if (arg)
	{
		if (arg[0] == 'r')
			return (1);
		else if (arg[0] == '%')
			return (g_op_tab[head->oper->num].size_dir);
		else if (arg[0] == ':' || ft_isdigit(arg[0]) == 1 ||
			(arg[0] == '-' && ft_isdigit(arg[1]) == 1))
			return (2);
	}
	return (0);
}

static	int	size_code(t_data *d)
{
	int		size;
	t_while	*head;

	size = 0;
	head = d->list;
	while (head)
	{
		head->size = 0;
		head->size++;
		if (head->oper)
		{
			if (g_op_tab[head->oper->num].carry == 1)
				head->size++;
			head->size += code_argv(head->oper->av1, head);
			head->size += code_argv(head->oper->av2, head);
			head->size += code_argv(head->oper->av3, head);
			size += head->size;
		}
		head = head->next;
	}
	return (size);
}

void		write_name_comment(t_data *d)
{
	int		i;

	i = 0;
	while (d->cp_name[i])
	{
		out_in_file(d->cp_name[i], 1, d);
		i++;
	}
	out_in_file(0, PROG_NAME_LENGTH - i, d);
	out_in_file(0, 4, d);
	out_in_file(size_code(d), 4, d);
	i = 0;
	while (d->cp_comment[i])
	{
		out_in_file(d->cp_comment[i], 1, d);
		i++;
	}
	out_in_file(0, COMMENT_LENGTH - i, d);
	out_in_file(0, 4, d);
}

int			cw_strncmp(const char *s1, const char *s2)
{
	char		*str;

	str = ft_strndup(s2, 0, g_data.x - g_data.i - 1);
	if (ft_strcmp(s1, str) == 0)
	{
		if (str)
			free(str);
		return (1);
	}
	if (str)
		free(str);
	return (0);
}
