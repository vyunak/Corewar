/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_visual_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:15:43 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/23 19:15:47 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>
#include <libglKH.h>
#include <keys.h>

void	init_keys(void)
{
	key_handler_add(GLFW_KEY_LEFT, KEY_MONO_REPEAT, 0, 0, key_left);
	key_handler_add(GLFW_KEY_RIGHT, KEY_MONO_REPEAT, 0, key_right_condition,
			key_right);
	key_handler_add(GLFW_KEY_ESCAPE, KEY_RELEASE, 0, 0, key_escape);
	key_handler_add(GLFW_KEY_SPACE, KEY_RELEASE, 0, 0, key_space);
	key_handler_add(GLFW_KEY_LEFT_SHIFT, KEY_RELEASE, 0, 0, key_shift);
}

char	corewar_visual_init(t_champ const **const restrict champions,
							t_arena const *const restrict arena,
							t_carriage **const restrict carriages)
{
	if (!glfwInit())
		exit_error("glfw init error");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	g_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "", 0, 0);
	glfwMakeContextCurrent(g_window);
	glfwSwapInterval(0);
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		exit_error("glew init error");
	if (!string_init(FONT_PATH))
		exit_error("string init error");
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glfwSetWindowPos(g_window, 50, 50);
	glfwGetFramebufferSize(g_window, &g_w_width, &g_w_height);
	glViewport(0, 0, g_w_width, g_w_height);
	init_set_drawable_elems(champions, arena, carriages);
	key_handler_init(g_window);
	init_keys();
	return (1);
}
