/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:30:55 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:30:59 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*srcs;
	char		*p_dst;

	if (!src)
		return (NULL);
	i = 0;
	srcs = src;
	p_dst = dst;
	while (i < n)
	{
		p_dst[i] = srcs[i];
		i++;
	}
	return (p_dst);
}
