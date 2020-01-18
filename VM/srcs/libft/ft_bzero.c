/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:51:57 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/19 15:53:00 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	char	*str;

	if (s && n > 0)
	{
		str = s;
		while (n--)
			str[n] = '\0';
	}
}
