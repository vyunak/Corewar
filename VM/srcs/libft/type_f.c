/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 18:14:04 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:34:59 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double		cast_f(va_list args, t_main tmp)
{
	long double	nbr;

	if ((tmp.type == 'f' || tmp.type == 'F') && tmp.castm == FL)
		nbr = va_arg(args, long double);
	else
		nbr = va_arg(args, double);
	return (nbr);
}

static char				*round_float(char *fr, __uint128_t *hq,
	t_main *lst, int i)
{
	i = (lst->rigor <= 0) ? 6 : lst->rigor;
	if (i >= 0 && fr[i] >= '5')
	{
		if (fr[i] == '9')
		{
			while (fr[i] == '9')
			{
				(i == 0 && fr[i] == '9') ? *hq += 1 : 0;
				fr[i--] = '0';
			}
			fr[i]++;
		}
		else
		{
			if (fr[i - 1] != '9' && (fr[i] > '5' ||
				(fr[i] >= '5' && *hq % 2 == 0)))
				fr[i - 1]++;
			else if (fr[i] > '5' || (fr[i] >= '5' && *hq % 2))
			{
				fr[i] = '9';
				round_float(fr, hq, lst, 0);
			}
		}
	}
	return (fr);
}

static void				handle_flags(t_sp *sp, t_main str,
					char *n1)
{
	int	rigor;
	int b1;

	if ((str.hash > 0 && str.rigor < 0) || (str.hash == 0 && str.rigor >= 0))
		rigor = 1;
	else
		rigor = 0;
	(str.rigor == 0) ? b1 = 6 : 0;
	(str.rigor < 0) ? b1 = 0 : 0;
	(str.rigor > 0) ? b1 = str.rigor - 1 : 0;
	rigor = (ft_strlen(n1) + b1 + rigor);
	((str.plus > 0 && str.fminus != 1) ||
		(str.plus > 0 && str.rigor < 0)) ? (sp->prefix = "+") : 0;
	(str.fminus == 1) ? (sp->prefix = "-") : 0;
	sp->start = str.width - ((str.rigor >= 0) ? str.rigor : 0) -
	((sp->prefix) ? 1 : 0) - rigor - str.space;
	(sp->start < 0) ? (sp->start = 0) : 0;
	(str.minus == 1 || (str.fminus == 1 && str.minus == 1)) ?
	(sp->end = sp->start) : 0;
	(str.minus == 1 || (str.fminus == 1 && str.minus == 1)) ?
	(sp->start = 0) : 0;
	(str.zero == 1 && str.rigor < 0) ? (sp->zero += sp->start) : 0;
	(str.zero == 1 && str.rigor < 0) ? (sp->start = 0) : 0;
}

int						f_odd(char *n1, char *n2, t_main str)
{
	t_sp				spaces;
	int					res;

	res = 0;
	spaces = set_space();
	handle_flags(&spaces, str, n1);
	(str.space > 0 && str.fminus == 0 && str.plus == 0) ?
		(res += printf_putchar(' ')) : 0;
	while (spaces.start-- > 0)
		res += printf_putchar(' ');
	(spaces.prefix) ? (res += printf_putstr(spaces.prefix)) : 0;
	while (spaces.zero-- > 0)
		res += printf_putchar('0');
	res += printf_putstr(n1);
	(str.rigor >= 0 || str.hash > 0) ? res += printf_putchar('.') : 0;
	(str.rigor >= 0) ? res += ft_str(n2, str.rigor) : 0;
	free(n1);
	free(n2);
	while (spaces.end-- > 0)
		res += printf_putchar(' ');
	return (res);
}

int						type_f(va_list args, t_main str)
{
	long double			nbr;
	__uint128_t			n1;
	char				*buff;
	int					count;

	nbr = cast_f(args, str);
	if (nbr != nbr)
		return (printf_putstr("nan"));
	else if (nbr * 2 == nbr && nbr != 0 && nbr < 0)
		return (printf_putstr("-inf"));
	else if (nbr * 2 == nbr && nbr != 0 && nbr > 0)
		return (printf_putstr("inf"));
	else
	{
		(1 / nbr < 0) ? ((str.fminus = 1) && (nbr *= -1)) : 0;
		(str.rigor <= 0) ? (count = 7) : 0;
		(str.rigor > 0) ? (count = str.rigor + 1) : 0;
		n1 = (__uint128_t)nbr;
		nbr = nbr - n1;
		buff = round_float(f_sin(nbr, 0, count, &buff), &n1, &str, 0);
		if (str.rigor < 0)
			if ((buff[0] >= '5' && n1 % 2) || (buff[0] > '5' && n1 % 2 == 0))
				n1++;
		return (f_odd(ft_uitoa(n1), buff, str));
	}
}
