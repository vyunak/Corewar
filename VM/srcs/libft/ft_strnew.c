/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:31:15 by vyunak            #+#    #+#             */
/*   Updated: 2019/07/19 15:53:14 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	size_t	i;
	char	*buff;

	i = 0;
	if (!(buff = ft_memalloc(size + 1)))
		return (0);
	ft_bzero(buff, size + 1);
	return (buff);
}
