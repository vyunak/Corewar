/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:22:44 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 18:10:16 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define MI 2147483648

static	void	set_null(int *n1, int *n2)
{
	*n1 = 0;
	*n2 = 0;
}

char			*ft_itoa(int nbr)
{
	char		*a;
	int			sign;
	int			len;
	int			n;

	if (nbr <= -MI)
		return (ft_strdup("-2147483648"));
	set_null(&sign, &len);
	(nbr < 0) ? (sign = 1) && (nbr *= -1) : 0;
	n = nbr;
	while (n > 0 && ++len >= 0)
		n /= 10;
	(len <= 0) ? len = 1 : 0;
	if (!(a = ft_strnew(len + sign)))
		return (0);
	(sign == 1) ? (a[0] = '-') && (len++) : 0;
	(nbr == 0) ? (a[0] = '0') : 0;
	a[len--] = '\0';
	while (nbr > 0)
	{
		a[len] = nbr % 10 + '0';
		nbr /= 10;
		len--;
	}
	return (a);
}
