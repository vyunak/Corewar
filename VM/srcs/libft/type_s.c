/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:28:35 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/07 16:40:24 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			hand_null(int **str, t_main *tm)
{
	(*str == 0) ? (tm->type = 's') : 0;
	(*str == 0) ? (tm->castm = 0) : 0;
	(*str == 0) ? (*str = (int*)"(null)") : 0;
}

static int		*hand_rigor(t_main *tm, int *n, int *l, int *str)
{
	int		i;

	*l = 0;
	*n = 0;
	i = -1;
	((*tm).rigor < 0) ? (str = (int*)ft_strdup("")) : 0;
	if (((*tm).type == 'S' || (*tm).castm == L) && (*tm).rigor != -1)
	{
		while (str[++i])
			if (*l + ft_get_size(str[i]) <= (*tm).rigor || (*tm).rigor <= 0)
			{
				*l += ft_get_size(str[i]);
				*n += 1;
			}
	}
	else
	{
		if ((*tm).rigor > 0)
			(str = (int*)ft_strsub((char*)str, 0, (*tm).rigor)) ?
				(*tm).usub = 1 : 0;
		*l = ft_strlen((char*)str);
	}
	return (str);
}

int				print_s(t_sp sp, t_main tm, int n, int *str)
{
	int			i;
	int			d;

	i = 0;
	while (sp.start-- > 0)
		i += printf_putchar(' ');
	while (sp.zero-- > 0)
		i += printf_putchar('0');
	if (tm.type == 'S' || tm.castm == L)
	{
		d = -1;
		while (str[++d] && n-- > 0)
			i += printf_putchar(str[d]);
	}
	else
		i += printf_putstr((char*)str);
	while (sp.end-- > 0)
		i += printf_putchar(' ');
	(tm.usub > 0) ? free(str) : 0;
	return (i);
}

static void		hand_flags(t_main tm, int l, t_sp *sp)
{
	*sp = set_space();
	sp->start = tm.width - l;
	(sp->start < 0) ? (sp->start = 0) : 0;
	(tm.minus > 0) ? (sp->end += sp->start) && (sp->start = 0) : 0;
	(tm.zero == 1) ? (sp->zero += sp->start) && (sp->start = 0) : 0;
}

int				type_s(va_list args, t_main tm)
{
	int		*str;
	t_sp	sp;
	int		l;
	int		n;

	str = va_arg(args, int*);
	hand_null(&str, &tm);
	str = hand_rigor(&tm, &n, &l, str);
	hand_flags(tm, l, &sp);
	return (print_s(sp, tm, n, str));
}
