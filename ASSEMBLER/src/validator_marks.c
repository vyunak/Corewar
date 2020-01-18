/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_marks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashypilo <ashypilo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 15:47:01 by ashypilo          #+#    #+#             */
/*   Updated: 2019/08/21 17:01:06 by ashypilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

static	int			search_marks_after(t_while *head, char *arg)
{
	t_while			*search;
	t_marks			*tmp;

	search = head;
	while (search)
	{
		if (search->marks)
		{
			tmp = search->marks;
			while (tmp)
			{
				if (ft_strcmp(arg, tmp->mark) == 0)
					return (0);
				tmp = tmp->next;
			}
		}
		search = search->prev;
	}
	return (1);
}

static	int			search_marks(t_while *head, char *arg)
{
	t_while			*search;
	t_marks			*tmp;

	search = head;
	while (search)
	{
		if (search->marks)
		{
			tmp = search->marks;
			while (tmp)
			{
				if (ft_strcmp(arg, tmp->mark) == 0)
					return (0);
				tmp = tmp->next;
			}
		}
		search = search->next;
	}
	if (search_marks_after(head, arg) == 0)
		return (0);
	return (1);
}

static int			transfer_marks(char *av, t_while *head)
{
	if (av[0] == '%' && av[1] == ':')
	{
		if (search_marks(head, &av[2]) == 1)
			return (1);
	}
	else if (av[0] == ':')
	{
		if (search_marks(head, &av[1]) == 1)
			return (1);
	}
	return (0);
}

int					validator_marks(t_data *d)
{
	t_while			*head;

	head = d->list;
	while (head)
	{
		if (head->oper && head->oper->av1)
			if (transfer_marks(head->oper->av1, head) == 1)
				return (1);
		if (head->oper && head->oper->av2)
			if (transfer_marks(head->oper->av2, head) == 1)
				return (1);
		if (head->oper && head->oper->av3)
			if (transfer_marks(head->oper->av3, head) == 1)
				return (1);
		head = head->next;
	}
	return (0);
}
