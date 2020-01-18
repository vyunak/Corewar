/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format&parse_agv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:50:06 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:50:42 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int				valid_argv(char ***str)
{
	int			x;
	int			i;
	int			res[2];

	x = -1;
	ft_bzero(&res, sizeof(res));
	while (++x < g_data.d)
	{
		i = 0;
		while (white_space((*str)[x][i]))
			i++;
		if (x == 0)
			res[0] += calc(&(*str)[x][i], g_op_tab[g_data.h].ac.arg1);
		else if (x == 1)
			res[0] += calc(&(*str)[x][i], g_op_tab[g_data.h].ac.arg2);
		else if (x == 2)
			res[0] += calc(&(*str)[x][i], g_op_tab[g_data.h].ac.arg3);
		if (res[0] == res[1])
			return (0);
		res[1] = x;
	}
	if (res[0] == g_data.o)
		return (0);
	return (1);
}

int				len_comm(const char *str)
{
	int			x;
	int			len;

	x = 0;
	len = 0;
	while (str[x] != '\0')
	{
		if (str[x] == SEPARATOR_CHAR)
			len++;
		x++;
	}
	return ((len > 2) ? -1 : len);
}

char			*write_arg(char **str)
{
	int			x;
	int			e;
	char		*st;

	x = 0;
	while (white_space((*str)[x]))
		x++;
	e = x;
	while (((*str)[e] && ft_islabel((*str)[e])) || (*str)[e] == ':' ||
		(*str)[e] == '%' || (*str)[e] == '-')
		e++;
	st = ft_strndup((*str), x, e - 1);
	return (st);
}

int				vy_free_arr(char ***str)
{
	char	**stre;

	stre = *str;
	if (*stre && **stre)
	{
		while (*stre != NULL)
		{
			(*stre) ? free(*stre) : 0;
			stre++;
		}
		(*str) ? free(*str) : 0;
	}
	(*str && !**str) ? free(*str) : 0;
	return (1);
}

void			create_new_oper(t_while **tmp)
{
	(*tmp)->next = (t_while*)malloc(sizeof(t_while));
	ft_bzero(&*(*tmp)->next, sizeof(t_while));
	(*tmp) = (*tmp)->next;
}
