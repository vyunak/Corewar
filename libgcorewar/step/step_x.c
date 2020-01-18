/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:32:12 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:32:13 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

static char	init_f(const char new_position)
{
	if (!-new_position || (g_x.position == -new_position && !g_x.init))
		return (1);
	if (g_x.init)
		g_x.color.w = 0.0f;
	g_x.draw = 1;
	return (0);
}

static char	between_step(const char new_position)
{
	g_x.position = -new_position;
	g_x.model.matrix[13] = g_str_champions[-new_position - 1]->position.y;
	g_x.color = g_str_champions[-new_position - 1]->color;
	g_x.color.w = 0.0f;
	return (0);
}

static char	end(const char new_position)
{
	g_x.draw = 1;
	g_x.color = g_str_champions[-new_position - 1]->color;
	g_x.model.matrix[13] = g_str_champions[-new_position - 1]->position.y;
	g_x.position = -new_position;
	g_x.init = 0;
	return (1);
}

char		x_step(const double time, const char init, const char new_position)
{
	static	double	start = 0;

	if (init)
	{
		start = time;
		return (init_f(new_position));
	}
	else if (!g_x.init && (time - start) < g_step_time * X_T)
		g_x.color.w = 1.0f - (time - start) / (g_step_time * X_T);
	else if ((time - start) > g_step_time * X_T && (time - start) <
												g_step_time - g_step_time * X_T
					&& (g_x.color.w != 0 || g_x.position != new_position))
		return (between_step(new_position));
	else if ((time - start) > g_step_time - g_step_time * X_T
											&& (time - start) <= g_step_time)
		g_x.color.w = (time - start - (g_step_time - g_step_time * X_T))
														/ (g_step_time * X_T);
	else if ((time - start) > g_step_time)
		return (end(new_position));
	return (0);
}
