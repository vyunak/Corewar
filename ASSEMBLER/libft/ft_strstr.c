/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:35:01 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 17:53:00 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int d;
	int x;

	i = 0;
	x = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		d = 0;
		x = i;
		while (haystack[x] == needle[d])
		{
			if (haystack[x] == needle[d] && needle[d + 1] == '\0')
				return ((char*)(haystack + x) - d);
			d++;
			x++;
		}
		i++;
	}
	return (NULL);
}
