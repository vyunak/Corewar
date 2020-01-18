/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:55:36 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:55:40 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	dstl;
	size_t	srcl;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	dstl = ft_strlen(dst);
	srcl = ft_strlen(src);
	if (n < dstl)
		return (srcl + n);
	while (dst[i] != '\0')
		i++;
	while (src[x] && i < (n - 1))
	{
		dst[i] = src[x];
		i++;
		x++;
	}
	dst[i] = '\0';
	return (dstl + srcl);
}
