/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vyunak <vyunak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 15:41:34 by vyunak            #+#    #+#             */
/*   Updated: 2019/04/04 18:13:09 by vyunak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_fd(int nb, int fd)
{
	unsigned int	i;
	char			x;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
	}
	i = nb;
	if (i >= 10)
		ft_putnbr_fd(i / 10, fd);
	x = (i % 10) + '0';
	ft_putchar_fd(x, fd);
}
