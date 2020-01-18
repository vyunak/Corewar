/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:21:34 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:33:13 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			number_cut(const char *format, int *i)
{
	int		num_buff;
	char	*buff;
	int		n;

	num_buff = *i;
	while (format[(*i)] >= '0' && format[(*i)] <= '9')
		(*i)++;
	if (!(buff = ft_strsub(format, num_buff, (*i) - num_buff)))
		return (0);
	n = ft_atoi(buff);
	(buff) ? free(buff) : 0;
	return (n);
}

int			hand_type(va_list args, t_main tm)
{
	int d;

	d = 0;
	if (tm.type == 'd' || tm.type == 'D' || tm.type == 'i')
		return (type_int(args, tm));
	else if (tm.type == 'x' || tm.type == 'X' || tm.type == 'p')
		return (type_x(args, tm));
	(tm.type == 'o' || tm.type == 'O') ? (d = type_o(args, tm)) : 0;
	(tm.type == 'u' || tm.type == 'U') ? (d = type_unsigned(args, tm)) : 0;
	(tm.type == 'c' || tm.type == 'C') ? (d = type_c(args, tm)) : 0;
	(tm.type == 's' || tm.type == 'S') ? (d = type_s(args, tm)) : 0;
	(tm.type == 'f' || tm.type == 'F') ? (d = type_f(args, tm)) : 0;
	return (d);
}

void		hand_other(const char *format, int *i, t_main *tm)
{
	int b;

	(isflag(format[(*i)])) ? set_flag(tm, format[(*i)++]) : 0;
	if (format[(*i)] >= '1' && format[(*i)] <= '9')
		tm->width = number_cut(format, i);
	if (format[(*i)] == '.')
	{
		(*i)++;
		b = number_cut(format, i);
		(b == 0) ? (tm->rigor = -1) : 0;
		(b != 0) ? (tm->rigor = b) : 0;
	}
	(iscastm(format[(*i)])) ? tm->castm = set_castm(format, tm, i) : 0;
}

int			check_flag(char c, int *l, va_list args, t_main tm)
{
	if (istype(c))
	{
		tm.type = c;
		*l += hand_type(args, tm);
		return (1);
	}
	if (c != '.' && c != '\0' && !isflag(c) && !ft_isdigit(c) &&
		!iscastm(c) && !istype(c))
	{
		*l += print_c(tm, c);
		return (1);
	}
	return (0);
}

int			ft_printf(char *format, ...)
{
	int		x;
	int		l;
	t_main	tm;
	va_list	args;

	x = -1;
	l = 0;
	va_start(args, format);
	while (format[++x])
	{
		if (format[x] == '%')
		{
			tm = set_tm();
			x++;
			while (!check_flag(format[x], &l, args, tm))
			{
				hand_other(format, &x, &tm);
				if (format[x] == '\0')
					return (l);
			}
		}
		else
			l += printf_putchar(format[x]);
	}
	return (l);
}
