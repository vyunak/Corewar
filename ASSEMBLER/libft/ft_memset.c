/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:32:14 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 15:32:54 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *b, int c, size_t len)
{
	char	*rr;
	size_t	i;

	if (!b)
		return (b);
	rr = b;
	i = 0;
	while (i < len)
		rr[i++] = c;
	return (b);
}
