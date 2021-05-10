/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:27:48 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/10 16:22:38 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		fill_width_nbr(int len, int zero, int width, int pre)
{
	int		ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1 && pre == -1)
			ret += ft_putchar('0');
		else
			ret += ft_putchar(' ');
		len++;
	}
	return (ret);
}

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

int		padding(int len, int pre)
{
	int		ret;

	ret = 0;
	if (pre <= len || pre < 0)
		return (0);
	else
	{
		while (len < pre)
		{
			ret += ft_putchar('0');
			len++;
		}
		return (ret);
	}
}

int		print_decimal(int d, t_option *option)
{
	int		sign;
	int		ret;
	int		len;

	if (d < 0)
	{
		sign = 1;
		d *= -1;
	}
	else
		sign = 0;
	ret = 0;
	len = decimal_digit(d);
	if (sign == 1 && option->zero == 1 && option->pre < 0)
	{
		ft_putchar('-');
		ret++;
		sign = 0;
	}
	if (option->minus == 1)
	{
		if (sign == 1)
		{
			ft_putchar('-');
			ret++;
		}
		ret += padding(len, option->pre);
		ft_putnbr(d);
		ret += len;
		len = ret;
	}
	if (sign == 1)
		ret += fill_width_nbr(len + 1, option->zero, option->width, option->pre);
	else
		ret += fill_width_nbr(len, option->zero, option->width, option->pre);
	if (option->minus == 0)
	{
		if (sign == 1)
		{
			ft_putchar('-');
			ret++;
		}
		ret += padding(len, option->pre);
		ft_putnbr(d);
		ret += len;
		len = ret;
	}
	return (ret);
}
