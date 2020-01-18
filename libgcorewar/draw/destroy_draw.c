/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:48:50 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:48:51 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libglKH.h>
#include <libgcorewar.h>

static void	cycle_body(const double time, char *const tmp, char *const tmp_1)
{
	glClearColor(0.14901960784f, 0.14901960784f, 0.14901960784f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glfwPollEvents();
	key_handle(time);
	if (!*tmp)
	{
		*tmp = str_static_animation_destroy(0, time);
		frames_draw();
		lines_draw();
		if (*tmp)
			*tmp_1 = string_winner_animation_init(1, time);
	}
	else
		*tmp_1 = string_winner_animation_init(0, time);
	string_draw();
	glfwSwapBuffers(g_window);
}

void		destroy_draw(void)
{
	double	time;
	char	tmp;
	char	tmp_1;

	glfwSetTime(0);
	time = glfwGetTime();
	tmp_1 = 0;
	tmp = str_static_animation_destroy(1, time);
	while ((!tmp || !tmp_1) && !glfwWindowShouldClose(g_window))
	{
		time = glfwGetTime();
		cycle_body(time, &tmp, &tmp_1);
	}
	while (!glfwWindowShouldClose(g_window))
	{
		time = glfwGetTime();
		glfwPollEvents();
		key_handle(time);
	}
}
