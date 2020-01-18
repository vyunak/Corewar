/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_winner_animation_init.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:43:41 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:43:42 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

char	string_winner_animation_init(const char init, const double time)
{
	static	double		start;

	if (init)
	{
		start = time;
		return (0);
	}
	else if ((time - start) > STR_S_T)
	{
		g_str_winner->color.w = 1.0f;
		return (1);
	}
	g_str_winner->color.w = ((time - start) / STR_S_T);
	return (0);
}
