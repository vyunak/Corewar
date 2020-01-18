/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:24:32 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:30:04 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t		cast_int(va_list args, t_main tm)
{
	intmax_t	n;

	if (tm.castm == L || tm.type == 'D')
		n = va_arg(args, long);
	else if (tm.castm == H)
		n = (short)va_arg(args, int);
	else if (tm.castm == HH)
		n = (char)va_arg(args, int);
	else if (tm.castm == LL)
		n = va_arg(args, long long);
	else if (tm.castm == J)
		n = va_arg(args, intmax_t);
	else if (tm.castm == Z)
		n = va_arg(args, size_t);
	else
		n = va_arg(args, int);
	return (n);
}

void			hand_flags(t_sp *sp, char *str, intmax_t nbr, t_main tm)
{
	sp->zero = tm.rigor - ft_strlen(str);
	(sp->zero < 0) ? (sp->zero = 0) : 0;
	sp->start = tm.width - sp->zero - ft_strlen(str) -
		ft_strlen(sp->prefix);
	(sp->start < 0) ? (sp->start = 0) : 0;
	(tm.plus > 0 && nbr >= 0 && !sp->prefix) ? (sp->prefix = "+") &&
		(sp->start -= ft_strlen(sp->prefix)) : 0;
	if (tm.space == 1 && nbr >= 0 && sp->prefix == 0)
	{
		sp->prefix = " ";
		sp->start -= ft_strlen(sp->prefix);
	}
	(tm.minus > 0) ? (sp->end = sp->start) : 0;
	(tm.minus > 0) ? (sp->start = 0) : 0;
	(tm.zero > 0 && tm.rigor == 0) ? (sp->zero += sp->start) : 0;
	(tm.zero > 0 && tm.rigor == 0) ? (sp->start = 0) : 0;
}

int				print_int(t_sp sp, char *str)
{
	int			i;

	i = 0;
	while (sp.start-- > 0)
		i += printf_putchar(' ');
	(sp.prefix) ? i += printf_putstr(sp.prefix) : 0;
	while (sp.zero-- > 0)
		i += printf_putchar('0');
	i += printf_putstr(str);
	while (sp.end-- > 0)
		i += printf_putchar(' ');
	free(str);
	return (i);
}

int				type_int(va_list args, t_main tm)
{
	intmax_t	nbr;
	char		*str;
	char		*buff;
	t_sp		sp;

	nbr = cast_int(args, tm);
	sp = set_space();
	if (nbr == 0 && tm.rigor < 0)
		str = ft_strdup("");
	else
		str = ft_itoa(nbr);
	if (nbr / 1 < 0)
	{
		sp.prefix = "-";
		buff = str;
		str = ft_strsub(str, 1, ft_strlen(str) - 1);
		free(buff);
	}
	hand_flags(&sp, str, nbr, tm);
	return (print_int(sp, str));
}
