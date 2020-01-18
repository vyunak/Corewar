/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 15:47:49 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:32:41 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_main	set_tm(void)
{
	t_main	tm;

	tm.hash = 0;
	tm.minus = 0;
	tm.fminus = 0;
	tm.plus = 0;
	tm.space = 0;
	tm.zero = 0;
	tm.width = 0;
	tm.rigor = 0;
	tm.castm = 0;
	tm.type = 0;
	tm.usub = 0;
	return (tm);
}

t_sp	set_space(void)
{
	t_sp	sp;

	sp.start = 0;
	sp.end = 0;
	sp.zero = 0;
	sp.prefix = 0;
	return (sp);
}

void	set_flag(t_main *tm, char flag)
{
	(flag == '#') ? (tm->hash = 1) : 0;
	(flag == '-') ? (tm->minus = 1) : 0;
	(flag == '+') ? (tm->plus = 1) : 0;
	(flag == '0') ? (tm->zero = 1) : 0;
	(flag == ' ') ? (tm->space = 1) : 0;
}

int		set_castm(const char *format, t_main *tm, int *i)
{
	if (format[(*i)] == 'L' && FL > tm->castm)
		tm->castm = FL;
	else if (format[(*i)] == 'z' && Z > tm->castm)
		tm->castm = Z;
	else if (format[(*i)] == 'j' && J > tm->castm)
		tm->castm = J;
	else if (format[(*i)] == 'l' && format[(*i) + 1] == 'l' &&
		LL > tm->castm)
		tm->castm = LL;
	else if (format[(*i)] == 'l' && L > tm->castm)
		tm->castm = L;
	else if (format[(*i)] == 'h' && format[(*i) + 1] == 'h' &&
		HH > tm->castm)
		tm->castm = HH;
	else if (format[(*i)] == 'h' && H > tm->castm)
		tm->castm = H;
	(*i)++;
	(tm->castm == HH || tm->castm == LL) ? (*i)++ : 0;
	return (tm->castm);
}
