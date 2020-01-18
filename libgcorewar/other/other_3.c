/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:10:10 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:10:11 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libgcorewar.h>

void	my_memcpy(void *const src, void const *const dst, size_t len)
{
	char *const			a = (char*)src;
	char const *const	b = (char*)dst;

	while (len--)
		a[len] = b[len];
}
