/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 17:36:05 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:33:19 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	to_string(int nbr, int der)
{
	if (nbr >= 0 && nbr <= 9)
		return (nbr + '0');
	if (nbr >= 10 && nbr <= 16)
	{
		if (der == 0)
			return ('a' + nbr - 10);
		else
			return ('A' + nbr - 10);
	}
	return (0);
}

char		*ft_itoa_base(uintmax_t nbr, int base_t, int der)
{
	char		*res;
	int			l;
	uintmax_t	tmp;

	if (nbr <= 0)
		return (ft_strdup("0"));
	l = 0;
	tmp = nbr;
	while (tmp > 0)
	{
		tmp /= base_t;
		l += 1;
	}
	res = ft_strnew(l);
	if (!res)
		return (0);
	res[l] = '\0';
	while (nbr != 0)
	{
		l--;
		res[l] = to_string(nbr % base_t, der);
		nbr /= base_t;
	}
	return (res);
}
