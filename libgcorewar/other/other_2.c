/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:10:07 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:10:08 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static char	*create_array(const uintmax_t n)
{
	size_t		i;
	uintmax_t	j;

	i = 1;
	j = 1;
	while (n / j > 9)
	{
		j *= 10;
		i++;
	}
	return ((char*)malloc(sizeof(char) * (i + 1)));
}

static void	set_res(char *const restrict res, uintmax_t i, uintmax_t n)
{
	int j;

	j = 0;
	while (i > 0)
	{
		res[j] = (char)(n / i + 48);
		n = n % i;
		i /= 10;
		j++;
	}
	res[j] = '\0';
}

char		*my_uitoa(const uintmax_t n)
{
	char *const restrict	res = create_array(n);
	uintmax_t				i;

	i = 1;
	if (!res)
		return (0);
	while (n / i > 9)
		i *= 10;
	set_res(res, i, n);
	return (res);
}

static char	convert_to_char(const unsigned char nb)
{
	if (nb <= 9)
		return (nb + 48);
	return ('A' + nb - 10);
}

void		my_base(unsigned char nb, char *str)
{
	str[1] = convert_to_char(nb % 16);
	nb /= 16;
	str[0] = convert_to_char(nb % 16);
	str[2] = '\0';
}
