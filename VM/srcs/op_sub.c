/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sub.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okaramel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:04:47 by okaramel          #+#    #+#             */
/*   Updated: 2019/09/12 18:04:50 by okaramel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int_fast32_t	get_arg(t_arena *pub, uint_fast32_t posit, uint_fast8_t size)
{
	int_fast32_t		res;
	t_bool				sign;

	if ((res = pub->cell[posit]) < 128)
		sign = 0;
	else if ((sign = 1))
		res = 255 - res;
	while (size-- > 1 && (++posit))
		res = (res << 8) + ((!sign) ?
		pub->cell[CM(posit)] : (255 - pub->cell[CM(posit)]));
	res = (!sign) ? res : -(res) - 1;
	return (res);
}

void			set_arg(t_arena **pub, uint_fast32_t posit, int_fast32_t arg)
{
	uint_fast8_t	size;

	size = REG_SIZE;
	while (size > 0)
	{
		(*pub)->cell[CM(posit + --size)] = arg % 256;
		arg >>= 8;
	}
}

char			code_to_siz(uint_fast8_t number, t_bool flag)
{
	if (number == REG_CODE)
		return (1);
	if (number == IND_CODE)
		return (IND_SIZE);
	if (number == DIR_CODE)
		return ((!flag) ? DIR_SIZE : IND_SIZE);
	return (0);
}

char			code_to_t(uint_fast8_t number)
{
	if (number == REG_CODE)
		return (T_REG);
	if (number == IND_CODE)
		return (T_IND);
	if (number == DIR_CODE)
		return (T_DIR);
	return (0);
}

int				check_reg(t_arena *pub, t_carriage **barman)
{
	uint_fast8_t		arg;

	arg = 0;
	if (g_optab[(*barman)->exec - 1].ac == 1)
		return (1);
	if ((*barman)->typarg[0] == 1 && (!(arg =
		get_arg(pub, CM((*barman)->posit + 2), 1)) || arg > 16))
		return (0);
	if ((*barman)->typarg[1] == 1 && (!(arg =
		get_arg(pub, CM((*barman)->posit + 2 +
		code_to_siz((*barman)->typarg[0], g_optab[(*barman)->exec -
		1].adir)), 1)) || arg > 16))
		return (0);
	if (g_optab[(*barman)->exec - 1].ac > 2 && (*barman)->typarg[2] == 1 &&
		(!(arg = get_arg(pub, CM((*barman)->posit + 2 +
		code_to_siz((*barman)->typarg[0], g_optab[(*barman)->exec - 1].adir) +
		code_to_siz((*barman)->typarg[1], g_optab[(*barman)->exec -
		1].adir)), 1)) || arg > 16))
		return (0);
	return (1);
}
