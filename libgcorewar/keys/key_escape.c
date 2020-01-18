/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_escape.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:01:23 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:01:24 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	key_escape(void *args)
{
	(void)args;
	glfwSetWindowShouldClose(g_window, GL_TRUE);
}
