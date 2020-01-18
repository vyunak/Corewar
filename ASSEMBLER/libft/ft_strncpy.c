/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:30:17 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/19 15:53:11 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		l;
	size_t		i;

	i = 0;
	l = ft_strlen(src);
	if (src)
	{
		while (i < n)
		{
			if (i > l)
				dst[i] = '\0';
			else
				dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
