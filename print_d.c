/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:27:48 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/13 12:16:41 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		check_padding(int d, int len, t_option *option)
{
	int		ret;

	ret = len;
	if (ret < option->pre)
		ret = option->pre;
	if (d < 0)
		ret += 1;
	if (d == 16)
		ret += 2;
	return (ret);
}

int		fill_width_nbr(int cnt, int pad, t_option *option)
{
	int		ret;

	ret = 0;
	if (option->minus == 1)
	{
		while (cnt < option->width)
		{
			ret += ft_putchar(' ');
			cnt += 1;
		}
	}
	else
	{
		while (cnt < option->width - pad)
		{
			if (option->zero == 1 && option->pre < 0)
				ret += ft_putchar('0');
			else
				ret += ft_putchar(' ');
			cnt++;
		}
	}
	return (ret);
}

int		padding(int d, int len, int sign, t_option *option)
{
	int		cnt;

	cnt = 0;
	if (sign == 0 && d < 0)
		cnt += ft_putchar('-');
	if (option->pre > len || option->pre >= 0)
	{
		while (len < option->pre)
		{
			cnt += ft_putchar('0');
			len++;
		}
	}
	if (d == 0 && option->pre == 0)
	{
		if (option->width == 0)
			return (0);
		else
			cnt += ft_putchar(' ');
	}
	else
		cnt += ft_putnbr(d);
	return (cnt);
}

int		print_decimal(int d, t_option *option)
{
	int		len;
	int		cnt;
	int		pad;
	int		sign;

	cnt = 0;
	sign = 0;
	len = decimal_digit(d);
	pad = check_padding(d, len, option);
	if (d < 0 && option->pre < 0 && (option->minus == 1 || option->zero == 1))
	{
		cnt += ft_putchar('-');
		pad -= 1;
		sign = 1;
	}
	if (option->minus == 1)
		cnt += padding(d, len, sign, option);
	cnt += fill_width_nbr(cnt, pad, option);
	if (option->minus == 0)
		cnt += padding(d, len, sign, option);
	return (cnt);
}
