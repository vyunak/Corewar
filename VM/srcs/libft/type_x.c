/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:59:19 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:29:04 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	intmax_t		cast_x(va_list args, t_main tm)
{
	intmax_t			n;

	if (tm.castm != 0 || tm.type == 'p')
		n = va_arg(args, size_t);
	else
		n = (unsigned int)va_arg(args, unsigned long);
	if (tm.castm == H)
		n = (unsigned short)n;
	else if (tm.castm == HH)
		n = (unsigned char)n;
	return (n);
}

static	void			hand_flags(t_sp *sp, t_main tm, char *str, intmax_t nbr)
{
	*sp = set_space();
	(*sp).zero = tm.rigor - ft_strlen(str);
	((*sp).zero < 0) ? ((*sp).zero = 0) : 0;
	(*sp).start = tm.width - (*sp).zero - ft_strlen(str);
	((*sp).start < 0) ? ((*sp).start = 0) : 0;
	if ((tm.hash > 0 && nbr != 0) || tm.type == 'p')
	{
		(tm.type == 'x' || tm.type == 'p') ? ((*sp).prefix = "0x") : 0;
		(tm.type == 'X') ? ((*sp).prefix = "0X") : 0;
		(*sp).start -= ft_strlen((*sp).prefix);
	}
	(tm.minus > 0) ? ((*sp).end = (*sp).start) &&
		((*sp).start -= (*sp).start) : 0;
	(tm.zero > 0 && (*sp).start > 0 && tm.rigor == 0) ?
	((*sp).zero = (*sp).start) &&
		((*sp).start -= (*sp).start) : 0;
}

static	int				print_h(t_sp sp, char *str)
{
	int res;

	res = 0;
	while (sp.start-- > 0)
		res += printf_putchar(' ');
	(sp.prefix) ? res += printf_putstr(sp.prefix) : 0;
	while (sp.zero-- > 0)
		res += printf_putchar('0');
	res += printf_putstr(str);
	while (sp.end-- > 0)
		res += printf_putchar(' ');
	free(str);
	return (res);
}

int						type_x(va_list args, t_main tm)
{
	intmax_t			nbr;
	t_sp				sp;
	char				*str;

	nbr = cast_x(args, tm);
	if (nbr == 0 && tm.rigor < 0)
		str = ft_strdup("");
	else if (tm.type == 'x' || tm.type == 'p')
		str = ft_itoa_base(nbr, 16, 0);
	else
		str = ft_itoa_base(nbr, 16, 1);
	hand_flags(&sp, tm, str, nbr);
	return (print_h(sp, str));
}
