/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmatseku <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 15:00:37 by dmatseku          #+#    #+#             */
/*   Updated: 2019/09/24 15:00:38 by dmatseku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

void	key_left(void *args);

void	key_right(void *args);

char	key_right_condition(void);

void	key_escape(void *args);

void	key_space(void *args);

void	key_shift(void *args);

#endif
