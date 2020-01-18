/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:29:43 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:29:55 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*p_dst;

	if (src)
	{
		i = -1;
		p_dst = dst;
		while (++i < n)
		{
			p_dst[i] = *((unsigned char *)src + i);
			if (*((unsigned char *)src + i) == (unsigned char)c)
				return (dst + i + 1);
		}
	}
	return (NULL);
}
