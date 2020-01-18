/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:54:22 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:54:23 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>
#include <libglKH.h>
#include <unistd.h>

static void	cycle_body(const double time, char *const res1, char *const res2,
													const char new_position)
{
	glClearColor(0.14901960784f, 0.14901960784f, 0.14901960784f,
												0.14901960784f);
	glClear(GL_COLOR_BUFFER_BIT);
	frames_draw();
	if (!*res1)
		*res1 = str_step_carriage(0, time);
	if (!*res2)
		*res2 = x_step(time, 0, new_position);
	string_draw();
	g_carriages_draw();
	lines_draw();
	x_draw();
	glfwSwapBuffers(g_window);
}

void		step_draw(const char new_position)
{
	double	time;
	char	res1;
	char	res2;

	time = glfwGetTime();
	res1 = str_step_carriage(1, time);
	res2 = x_step(time, 1, new_position);
	while ((!res1 || !res2) && !glfwWindowShouldClose(g_window))
	{
		time = glfwGetTime();
		glfwPollEvents();
		key_handle(time);
		if (g_pause)
			continue;
		cycle_body(time, &res1, &res2, new_position);
	}
	if (glfwWindowShouldClose(g_window))
	{
		glfwTerminate();
		exit(0);
	}
}
