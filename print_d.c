/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:27:48 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/07 11:44:09 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


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

int		check_pre_num(int len, int pre)
{
	int		ret;

	ret = 0;
	if (pre <= len || pre < 0)
		return (0);
	else
	{
		while (len < pre)
		{
			ft_putchar('0');
			len++;
			ret++;
		}
		return (ret);
	}
}

int		print_decimal(int d, t_option *option)
{
	int		ret;
	int		len;

	ret = 0;
	len = decimal_digit(d);
	if (option->minus == 1)
	{
		if (d < 0)
		{
			ft_putchar('-');
			ret += 1;
			d *= -1;
		}
		ret += check_pre_num(len, option->pre);
		ft_putnbr(d);
		ret += len;
	}
	ret += fill_width(len, option->zero, option->width, option->minus);
	if (option->minus == 0)
	{
		if (d < 0)
		{
			ft_putchar('-');
			ret += 1;
			d *= -1;
		}
		ret += check_pre_num(len, option->pre);
		ft_putnbr(d);
		ret+=len;
	}
	return (ret);
}
