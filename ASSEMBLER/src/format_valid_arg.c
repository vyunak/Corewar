/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valig_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:48:59 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:49:25 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int				command_check(char *line)
{
	int			x;

	x = -1;
	while (++x < 16)
	{
		if (cw_strncmp(g_op_tab[x].op, &line[g_data.i]) == 1)
			return (x);
	}
	return (-1);
}

int				ft_arrlab(char **str)
{
	int			x;

	x = 0;
	while (str[x] != NULL)
		x++;
	return (x);
}

int				calc_arg2(char *str, int l)
{
	if (str[0] == '%' && str[1] != ':' && str[1] != '-' &&
		(witoutnum(&str[1]) > 0))
		return (0);
	else if (str[0] == '%' && str[1] == '-' && witoutnum(&str[2]) > 0)
		return (0);
	else if (str[0] == '%' && str[1] == ':' && ft_strislabel(&str[2]) == 0)
		return (0);
	else if (str[0] == '%' && str[1] == ':' && !str[2])
		return (0);
	if (ft_isdigit(str[1]) && witoutnum(&str[1]) > 0)
		return (0);
	if (g_calc_op[l].arg2 == 1 && str[1] && (str[1] == ':' ||
			(str[1] == '-' && str[2] && ft_isdigit(str[2])) ||
			ft_isdigit(str[1])))
		return (1);
	else
		return (0);
}

int				calc_arg3(char *str, int l)
{
	if (str[0] == ':' && ft_strislabel(&str[1]) == 0)
		return (0);
	else if (str[1] == ':' && !str[2])
		return (0);
	else if (str[0] == '-' && witoutnum(&str[1]) > 0)
		return (0);
	else if (str[0] != '-' && str[0] != ':' && witoutnum(&str[0]) > 0)
		return (0);
	if (g_calc_op[l].arg3 == 1)
		return (1);
	else
		return (0);
}

int				calc(char *str, int l)
{
	int			ac;

	if (str[0] == 'r' && st_end(&str[1]))
	{
		ac = ft_atoi(&str[1]);
		if (ac > 0 && ac <= 99 && g_calc_op[l].arg1 == 1 &&
			witoutnum(&str[1]) == 0 && !ft_isdigit(str[3]))
			return (1);
		else
			return (0);
	}
	else if (str[0] == '%' && (str[1] == ':' || str[1] == '-' ||
		white_space(str[1]) == 0) && st_end(&str[1]))
		return (calc_arg2(str, l));
	else if ((ft_isdigit(str[0]) || str[0] == ':' ||
		str[0] == '-') && st_end(&str[0]))
		return (calc_arg3(str, l));
	return (0);
}
