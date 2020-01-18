/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CWA_lib_p2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:48:13 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:48:40 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int				print_error(char *type)
{
	if (g_data.error != 1)
	{
		ft_printf("ERROR: %s\n", type);
		g_data.error = 1;
	}
	return (0);
}

int				ft_strislabel(char *str)
{
	int			x;
	int			as;

	x = -1;
	as = 0;
	while (str[++x] != '\0')
	{
		if (ft_islabel(str[x]) || str[x] == '_' || white_space(str[x]))
			as++;
		else
			return (0);
	}
	return (1);
}

int				ft_strnslabel(char *str, int end)
{
	int			x;
	int			as;

	x = 0;
	as = 0;
	while (str[x] != '\0' && x < end)
	{
		if (ft_islabel(str[x]) || str[x] == '_')
			as++;
		else
			return (0);
		x++;
	}
	return (1);
}

int				st_end(char *c)
{
	int			x;
	int			i;

	x = 0;
	i = 0;
	while (c[x] != '\0')
	{
		if (c[x] == COMMENT_CHAR || c[x] == ALT_COMMENT_CHAR)
			return (1);
		if (white_space(c[x]))
			i++;
		if (i > 0 && c[x] >= 33 && c[x] <= 122)
			return (0);
		x++;
	}
	return (1);
}

int				stmark(char *c)
{
	int			x;
	int			i;

	x = 0;
	i = 0;
	while (c[x] != '\0')
	{
		if (c[x] == COMMENT_CHAR || c[x] == ALT_COMMENT_CHAR)
			return (1);
		if (c[x] >= 33 && c[x] <= 122)
			return (0);
		x++;
	}
	return (1);
}
