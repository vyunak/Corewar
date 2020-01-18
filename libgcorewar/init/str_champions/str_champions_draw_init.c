/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_champions_draw_init.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 14:33:22 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 14:33:24 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static void	set_active(void)
{
	char			i;

	i = 0;
	while (i < g_number_of_champions)
	{
		g_str_champions[(int)i]->active = 1;
		i++;
	}
}

static void	step_champions(char *const restrict nb, const double time,
													const double start)
{
	char			dnb;

	dnb = (char)((time - start) / (STR_CH_T
			/ g_number_of_champions));
	while (*nb <= dnb)
	{
		g_str_champions[(int)*nb]->active = 1;
		(*nb)++;
	}
}

char		str_champions_draw_init(const char init, const double time)
{
	static double	start;
	static char		nb;

	if (init && STR_CH_T >= 0.1)
	{
		start = time;
		nb = 0;
		return (0);
	}
	else if (STR_CH_T < 0.1
	|| time - start > STR_CH_T || nb == g_number_of_champions)
	{
		set_active();
		return (1);
	}
	step_champions(&nb, time, start);
	return (0);
}
