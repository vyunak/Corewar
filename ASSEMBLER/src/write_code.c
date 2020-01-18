/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_code.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:40:01 by ashypilo          #+#    #+#             */
/*   Updated: 2019/08/21 17:01:14 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static	void	return_argv(t_data *d, char *arg)
{
	if (arg[0] == 'r')
	{
		d->num[d->x++] = '0';
		d->num[d->x++] = '1';
	}
	else if (arg[0] == '%')
	{
		d->num[d->x++] = '1';
		d->num[d->x++] = '0';
	}
	else if (arg[0] == ':' || ft_isdigit(arg[0]) == 1 ||
		(arg[0] == '-' && ft_isdigit(arg[1]) == 1))
	{
		d->num[d->x++] = '1';
		d->num[d->x++] = '1';
	}
}

static	void	code_type_argv(t_data *d, t_while *head)
{
	d->x = 0;
	if (d->num == NULL)
		d->num = (char*)malloc(sizeof(char) * 9);
	return_argv(d, head->oper->av1);
	if (head->oper->av2)
		return_argv(d, head->oper->av2);
	else
	{
		d->num[d->x++] = '0';
		d->num[d->x++] = '0';
	}
	if (head->oper->av3)
		return_argv(d, head->oper->av3);
	else
	{
		d->num[d->x++] = '0';
		d->num[d->x++] = '0';
	}
	d->num[d->x++] = '0';
	d->num[d->x++] = '0';
	d->num[d->x++] = '\0';
	d->x = ft_atoi_base(d->num, 2);
}

void			write_code(t_data *d)
{
	t_while		*head;
	int			i;

	head = d->list;
	while (head)
	{
		i = 0;
		if (head->oper)
		{
			out_in_file(head->oper->num + 1, 1, d);
			if (g_op_tab[head->oper->num].carry == 1)
			{
				code_type_argv(d, head);
				out_in_file(d->x, 1, d);
			}
			write_arg_in_file(d, head, head->oper->av1);
			write_arg_in_file(d, head, head->oper->av2);
			write_arg_in_file(d, head, head->oper->av3);
		}
		head = head->next;
	}
}
