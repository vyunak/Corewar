/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:24:34 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:30:14 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*f_sin(long double nbr, int i, int count, char **buff)
{
	long double	cent;
	char		*bu;

	bu = *buff;
	bu = (char *)malloc(sizeof(char) * (count + 1));
	cent = nbr;
	while (i < count)
	{
		bu[i] = cent * 10 + 48;
		cent *= 10;
		cent -= (__uint128_t)cent;
		i++;
	}
	return (bu);
}

int						ft_str(char const *s, int rigor)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	if (!s)
		return (0);
	if (s[0] == '\0')
		return (printf_putstr("000000"));
	(rigor == 0) ? (rigor = 6) : 0;
	while (i < rigor)
		res += printf_putchar(s[i++]);
	return (res);
}
