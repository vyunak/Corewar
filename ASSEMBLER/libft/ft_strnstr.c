/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:33:53 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 17:51:58 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	int i;
	int d;
	int x;

	i = 0;
	x = 0;
	if (nd[0] == '\0')
		return ((char*)hs);
	while (hs[i] != '\0' && (int)len > i)
	{
		d = 0;
		x = i;
		while (hs[x] == nd[d] && (int)len > x)
		{
			if (hs[x] == nd[d] && nd[d + 1] == '\0')
			{
				return ((char*)(hs + x) - d);
			}
			d++;
			x++;
		}
		i++;
	}
	return (NULL);
}
