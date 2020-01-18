/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 16:39:11 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:30:24 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			hand_flag(t_sp *sp, t_main tm, int c)
{
	*sp = set_space();
	if (tm.castm == L || tm.type == 'C')
		(*sp).start = tm.width - ft_get_size(c);
	else
		(*sp).start = tm.width - 1;
	((*sp).start < 0) ? ((*sp).start = 0) : 0;
	(tm.minus > 0) ? (((*sp).end += (*sp).start) && ((*sp).start = 0)) : 0;
	(tm.zero > 0) ? (((*sp).zero += (*sp).start) && ((*sp).start = 0)) : 0;
}

int					print_c(t_main tm, int c)
{
	int		l;
	t_sp	sp;

	l = 0;
	hand_flag(&sp, tm, c);
	while (sp.start-- > 0)
		l += printf_putchar(' ');
	while (sp.zero-- > 0)
		l += printf_putchar('0');
	if (tm.type == 'C' || tm.castm == L)
		l += printf_putchar(c);
	else
		l += printf_putchar((char)c);
	while (sp.end-- > 0)
		l += printf_putchar(' ');
	return (l);
}

int					type_c(va_list args, t_main tm)
{
	return (print_c(tm, va_arg(args, int)));
}
