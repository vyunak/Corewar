/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:35:11 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 18:06:47 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	x;
	char	*b;

	if (!s || !(b = ft_strnew(len)))
		return (0);
	i = -1;
	x = ft_strlen(s);
	while (++i < len && i < x)
		b[i] = s[i + start];
	return (b);
}
