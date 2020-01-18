/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CWA_lib_p1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 17:47:26 by vyunak            #+#    #+#             */
/*   Updated: 2019/08/21 17:47:57 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int				ft_islabel(int c)
{
	int			x;
	int			g;

	x = 0;
	g = 0;
	while (LABEL_CHARS[x] != '\0')
	{
		if (LABEL_CHARS[x] == c)
			g++;
		x++;
	}
	if (g == 0)
		return (0);
	return (1);
}

int				ft_strisalnum(char *str)
{
	int			x;
	int			as;

	x = -1;
	as = 0;
	while (str[++x] != '\0')
		if (str[x] >= 33 && str[x] <= 127)
			as++;
	return (as > 0);
}

int				ft_isascii_wn(int c)
{
	if ((c >= 33 && c <= 47) || (c >= 58 && c <= 127))
		return (1);
	return (0);
}

int				witoutnum(char *str)
{
	int		x;
	int		as;

	x = -1;
	as = 0;
	while (str[++x] != '\0')
		if (ft_isascii_wn(str[x]))
			as++;
	return (as > 0);
}

int				white_space(char x)
{
	if (x == ' ' || x == '\t' || x == '\n'
		|| x == '\r' || x == '\f' || x == '\v')
		return (1);
	return (0);
}
