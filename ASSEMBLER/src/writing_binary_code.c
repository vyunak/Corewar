/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writing_binary_code.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 16:37:28 by ashypilo          #+#    #+#             */
/*   Updated: 2019/08/21 17:00:14 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void				out_in_file(int32_t nbr, int size, t_data *d)
{
	unsigned int	tmp;
	int				i;
	unsigned int	max;
	char			*res;

	if (size == 1)
		max = 255;
	if (size == 2)
		max = 65535;
	if (size == 4)
		max = 4294967295;
	if (nbr < 0)
		tmp = max + nbr + 1;
	else
		tmp = nbr;
	res = ft_memalloc(sizeof(char) * size);
	i = size;
	while (--i >= 0)
	{
		res[i] = tmp % 256;
		tmp /= 256;
	}
	write(d->fd, res, size);
	free(res);
}

static	int			validator_argv(t_data *d)
{
	t_while			*head;

	head = d->list;
	while (head)
	{
		if (head->oper && g_op_tab[head->oper->num].ac.arg1 > 0 &&
			!head->oper->av1)
			return (1);
		if (head->oper && g_op_tab[head->oper->num].ac.arg2 > 0 &&
			!head->oper->av2)
			return (1);
		if (head->oper && g_op_tab[head->oper->num].ac.arg3 > 0 &&
			!head->oper->av3)
			return (1);
		head = head->next;
	}
	return (0);
}

static void			create_prev_list(t_data *d)
{
	t_while			*head;
	t_while			*pr;

	head = d->list;
	d->list->prev = NULL;
	pr = NULL;
	while (head)
	{
		if (pr)
			head->prev = pr;
		pr = head;
		head = head->next;
	}
}

void				writing_binary_code(t_data *d, t_files *tmp)
{
	if (!g_data.list->oper && !g_data.list->marks && g_data.error != 1)
		print_error("operation do not exist!");
	if ((g_data.comment == 0 || g_data.name == 0) && g_data.error != 1)
		print_error("name or comment do not exist!");
	if (!d->list->oper && g_data.error != 1)
		print_error("operation do not exist!");
	else if (g_data.error != 1)
	{
		create_prev_list(d);
		if (validator_argv(d) == 1 && g_data.error != 1)
			print_error("incorrect argument!");
		if (validator_marks(d) == 1 && g_data.error != 1)
			print_error("incorrect label!");
		if (g_data.error != 1)
		{
			d->fd = open(tmp->name, O_WRONLY | O_CREAT | O_TRUNC, 0777);
			out_in_file(COREWAR_EXEC_MAGIC, 4, d);
			write_name_comment(d);
			write_code(d);
			ft_printf("Writing output program to %s\n", tmp->name);
		}
	}
	else if (g_data.error == 1)
		ft_printf("%s: file error!\n", tmp->name_og);
}

int					check_last_line(char *all, size_t ld)
{
	size_t		lds;

	lds = 0;
	if (all)
	{
		while (all[lds] != '\0')
		{
			if (all[lds] == '\n')
				ld = lds;
			lds++;
		}
		while (all[ld] != '\0')
		{
			if (white_space(all[ld]) == 0)
				return (1);
			ld++;
		}
	}
	return (0);
}
