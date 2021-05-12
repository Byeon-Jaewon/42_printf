/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:54:10 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/12 14:25:04 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		decimal_digit(int d)
{
	int		ret;

	if (d == 0)
		ret = 1;
	else
		ret = 0;
	while (d != 0)
	{
		d /= 10;
		ret++;
	}
	return (ret);
}

int		unsigned_digit(unsigned int u)
{
	int		ret;

	if (u == 0)
		ret = 1;
	else
		ret = 0;
	while (u != 0)
	{
		u /= 10;
		ret++;
	}
	return (ret);
}

int		hex_digit(unsigned int d)
{
	int		ret;

	if (d == 0)
		ret = 1;
	else
		ret = 0;
	while (d != 0)
	{
		d /= 16;
		ret ++;
	}
	return (ret);
}
