/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_o.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:34:23 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:29:47 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	uintmax_t	cast_o(va_list args, t_main tm)
{
	uintmax_t n;

	if (tm.castm == L || tm.type == 'O')
		n = va_arg(args, unsigned long);
	else if (tm.castm == H)
		n = (unsigned short)va_arg(args, size_t);
	else if (tm.castm == HH)
		n = (unsigned char)va_arg(args, size_t);
	else if (tm.castm == LL)
		n = va_arg(args, long long);
	else if (tm.castm == J)
		n = va_arg(args, intmax_t);
	else if (tm.castm == Z)
		n = va_arg(args, size_t);
	else
		n = va_arg(args, unsigned int);
	return (n);
}

static	void		hand_flags(t_sp *sp, t_main tm, char *str)
{
	*sp = set_space();
	(*sp).zero = tm.rigor - ft_strlen(str);
	((*sp).zero < 0) ? ((*sp).zero = 0) : 0;
	(*sp).start = tm.width - (*sp).zero - ft_strlen(str);
	((*sp).start < 0) ? ((*sp).start = 0) : 0;
	if (tm.hash > 0 && str[0] != '0' && (*sp).zero == 0)
	{
		(*sp).prefix = "0";
		(*sp).start -= ft_strlen((*sp).prefix);
	}
	(tm.minus > 0) ? ((*sp).end = (*sp).start) &&
		((*sp).start -= (*sp).start) : 0;
	(tm.zero > 0 && tm.rigor == 0) ? ((*sp).zero = (*sp).start) &&
		((*sp).start -= (*sp).start) : 0;
}

static	int			print_o(t_sp sp, char *str)
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

int					type_o(va_list args, t_main tm)
{
	uintmax_t	nbr;
	t_sp		sp;
	char		*str;

	nbr = cast_o(args, tm);
	if (nbr == 0 && tm.rigor < 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base(nbr, 8, 0);
	hand_flags(&sp, tm, str);
	return (print_o(sp, str));
}
