/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_arg_in_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 17:46:48 by ashypilo          #+#    #+#             */
/*   Updated: 2019/08/21 16:53:42 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static	void	bite_step_in_forward(t_data *d, t_while *head, char *arg)
{
	t_while		*search;
	t_marks		*tmp;

	d->metk = 0;
	search = head;
	while (search)
	{
		if (search->marks)
		{
			tmp = search->marks;
			while (tmp)
			{
				if (ft_strcmp(arg, tmp->mark) == 0)
					d->x = 1;
				tmp = tmp->next;
			}
		}
		if (d->x == 0)
			d->metk += search->size;
		search = search->next;
	}
}

static void		search_marks(t_data *d, t_while *search, char *arg)
{
	t_marks		*tmp;

	tmp = search->marks;
	while (tmp)
	{
		if (ft_strcmp(arg, tmp->mark) == 0)
			d->x = 1;
		tmp = tmp->next;
	}
}

static	void	arg_marks(t_data *d, t_while *head, char *arg)
{
	t_while		*search;

	search = head;
	d->metk = 0;
	d->x = 0;
	while (search)
	{
		if (search->marks)
			search_marks(d, search, arg);
		search = search->prev;
		if (d->x == 0 && search)
			d->metk += search->size;
	}
	if (d->x == 0)
		bite_step_in_forward(d, head, arg);
	else
		d->metk *= -1;
	out_in_file(d->metk, g_op_tab[head->oper->num].size_dir, d);
}

void			write_arg_in_file(t_data *d, t_while *head, char *arg)
{
	if (arg)
	{
		if (arg[0] == 'r')
			out_in_file(ft_atoi(&arg[1]), 1, d);
		else if (arg[0] == '%' && arg[1] != ':')
			out_in_file(ft_atoi(&arg[1]),
					g_op_tab[head->oper->num].size_dir, d);
		else if (arg[0] == '%' && arg[1] == ':')
			arg_marks(d, head, &arg[2]);
		else if (arg[0] == ':')
			arg_marks(d, head, &arg[1]);
		else if (ft_isdigit(arg[0]) == 1 ||
			(arg[0] == '-' && ft_isdigit(arg[1]) == 1))
			out_in_file(ft_atoi(arg), 2, d);
	}
}

char			*search_s(char *str)
{
	int		i;
	char	*tmp;
	char	*tmps;

	i = 0;
	tmps = NULL;
	while (str[i] != '\0')
		i++;
	tmp = str;
	(i == 0) ? print_error("file name!") : 0;
	while (--i >= 0)
	{
		if (tmp[i] == 's' && tmp[i - 1] == '.')
			tmps = (ft_strndup(tmp, 0, i - 2));
	}
	if (tmps)
	{
		tmp = gnl_strjoin(tmps, ".cor");
		free(tmps);
	}
	else
		tmp = gnl_strjoin(tmps, ".cor");
	return (tmp);
}
