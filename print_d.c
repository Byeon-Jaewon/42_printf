/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:27:48 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/10 17:16:42 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		fill_width_nbr(int size, t_option *option)
{
	int		ret;

	ret = 0;
	while (size < option->width)
	{
		if (option->zero == 1 && option->pre == -1)
			ret += ft_putchar('0');
		else
			ret += ft_putchar(' ');
		size++;
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
	int		ret;
	int		len;
	int		sign;
	int		size;

	ret = 0;
	len = decimal_digit(d);
	if (len <= option->pre)
		size = option->pre;
	else
		size = len;
	if (d < 0)
	{
		sign = 1;
		d *= -1;
		size += 1;
	}
	else
		sign = 0;
	if (sign == 1 && option->zero == 1 && option->pre == -1)
	{
		sign = 0;
		ft_putchar('-');
		ret++;
	}
	if (option->minus == 1)
	{
		if (sign == 1)
		{
			ft_putchar('-');
			ret++;
		}
		ret += padding(len, option->pre);
		if (d == 0 && option->pre == 0)
		{
			if (option->width == 0)
				return (0);
			else
				ft_putchar(' ');
		}
		else
			ft_putnbr(d);
		ret += len;
	}
	ret += fill_width_nbr(size, option);
	if (option->minus == 0)
	{
		if (sign == 1)
		{
			ft_putchar('-');
			ret++;
		}
		ret += padding(len, option->pre);
		if (d == 0 && option->pre == 0)
		{
			if (option->width == 0)
				return (0);
			else
				ft_putchar(' ');
		}
		else
			ft_putnbr(d);
		ret += len;
	}
	return (ret);
}
