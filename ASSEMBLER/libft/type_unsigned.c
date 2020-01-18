/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 15:27:48 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/10 15:29:25 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t			cast_unsigned(va_list args, t_main tm)
{
	intmax_t b;

	if (tm.castm == L || tm.type == 'U')
		b = va_arg(args, unsigned long);
	else if (tm.castm == H)
		b = (unsigned short)va_arg(args, unsigned int);
	else if (tm.castm == HH)
		b = (unsigned char)va_arg(args, unsigned int);
	else if (tm.castm == LL)
		b = va_arg(args, unsigned long long);
	else if (tm.castm == J)
		b = va_arg(args, uintmax_t);
	else if (tm.castm == Z)
		b = va_arg(args, size_t);
	else
		b = va_arg(args, unsigned int);
	return (b);
}

static void			hand_flags(t_sp *sp, t_main tm, char *str)
{
	*sp = set_space();
	(*sp).zero = tm.rigor - ft_strlen(str);
	(*sp).zero < 0 ? (*sp).zero = 0 : 0;
	(*sp).start = tm.width - (*sp).zero - ft_strlen(str) -
		ft_strlen((*sp).prefix);
	(*sp).start < 0 ? (*sp).start = 0 : 0;
	tm.minus > 0 ? (*sp).end = (*sp).start : 0;
	tm.minus > 0 ? (*sp).start = 0 : 0;
	tm.zero > 0 && tm.rigor == 0 ? (*sp).zero = (*sp).start : 0;
	tm.zero > 0 && tm.rigor == 0 ? (*sp).start = 0 : 0;
}

static int			print_u(t_sp sp, char *str)
{
	int		res;

	res = 0;
	while (sp.start-- > 0)
		res += printf_putchar(' ');
	while (sp.zero-- > 0)
		res += printf_putchar('0');
	res += printf_putstr(str);
	while (sp.end-- > 0)
		res += printf_putchar(' ');
	free(str);
	return (res);
}

int					type_unsigned(va_list args, t_main tm)
{
	intmax_t	nbr;
	char		*str;
	t_sp		sp;

	nbr = cast_unsigned(args, tm);
	if (nbr == 0 && tm.rigor < 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base(nbr, 10, 1);
	hand_flags(&sp, tm, str);
	return (print_u(sp, str));
}
