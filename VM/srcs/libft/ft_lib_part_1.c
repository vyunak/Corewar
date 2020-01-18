/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_part_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:27:12 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:31:09 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_uitoa(__uint128_t number)
{
	char		*a;
	int			sign;
	int			len;
	__uint128_t	n;

	sign = 0;
	len = 0;
	n = number;
	while (n > 0 && ++len >= 0)
		n /= 10;
	(len == 0) ? len = 1 : 0;
	if (!(a = ft_strnew(len + sign)))
		return (0);
	(sign == 1) ? (a[0] = '-') && (len++) : 0;
	(number == 0) ? (a[0] = '0') : 0;
	a[len--] = '\0';
	while (number > 0)
	{
		a[len] = number % 10 + '0';
		number /= 10;
		len--;
	}
	return (a);
}

int				printf_putchar(int c)
{
	unsigned char	code[4];

	if (c <= 127 || MB_CUR_MAX != 4)
		code[0] = c;
	else if (c <= 2047)
	{
		code[0] = (c >> 6 & 31) | 192;
		code[1] = (c & 63) | 128;
	}
	else if (c <= 65535)
	{
		code[0] = (c >> 12 & 15) | 224;
		code[1] = (c >> 6 & 63) | 128;
		code[2] = (c & 63) | 128;
	}
	else
	{
		code[0] = (c >> 18 & 7) | 240;
		code[1] = (c >> 12 & 63) | 128;
		code[2] = (c >> 6 & 63) | 128;
		code[3] = (c & 63) | 128;
	}
	write(1, &code, ft_get_size(c));
	return (ft_get_size(c));
}

int				printf_putstr(char const *s)
{
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		res += printf_putchar(s[i]);
		i++;
	}
	return (res);
}
