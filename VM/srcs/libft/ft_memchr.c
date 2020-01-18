/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:30:05 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:30:10 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memchr(const void *s, int c, size_t n)
{
	size_t					i;
	const unsigned char		*src;

	if (s)
	{
		src = s;
		i = 0;
		while (i < n)
		{
			if (src[i] == (unsigned char)c)
				return ((void*)s + i);
			i++;
		}
	}
	return (NULL);
}
