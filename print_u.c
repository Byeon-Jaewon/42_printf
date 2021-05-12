/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:39:03 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/12 14:17:08 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_size_u(int len, t_option *option)
{
	int		size;

	size = len;
	if (size < option->pre)
		size = option->pre;
	if (size < option->width)
		size = option->width;
	return (size);
}

int		padding_u(unsigned int u, int len, t_option *option)
{
	int		cnt;

	cnt = 0;
	if (option->pre > len || option->pre >= 0)
	{
		while (len < option->pre)
		{
			cnt += ft_putchar('0');
			len++;
		}
	}
	if (u == 0 && option->pre == 0)
	{
		if (option->width == 0)
			return (0);
		else
			cnt += ft_putchar(' ');
	}
	else
		cnt += ft_putunbr(u);
	return (cnt);
}

/*int		fill_width_unbr(int cnt, int pad, t_option *option)
{
	int		ret;

	ret = 0;
	if (option->minus == 1)
	{
		while (cnt < option->width)
		{
			if (option->zero == 1 && option->pre < 0)
				ret += ft_putchar('0');
			else
				ret += ft_putchar(' ');
			cnt++;
		}
	}
	else
	{
		while (cnt < option->width - pad)
		{
			if (option->zero == 1 && option->pre == -1)
				ret += ft_putchar('0');
			else
				ret += ft_putchar(' ');
			cnt++;
		}
	}
	return (ret);
}*/

int		ft_putunbr(unsigned int n)
{
	int		ret;

	ret = 0;
	if (n > 9)
	{
		ret += ft_putunbr(n / 10);
	}
	ret += ft_putchar((n % 10) + '0');
	return (ret);
}

int		print_uint(unsigned int u, t_option *option)
{
	int		len;
	int		cnt;
	int		size;
	int		pad;

	cnt = 0;
	len = unsigned_digit(u);
	size = check_size_u(len, option);
	pad = check_padding(1, len, option);
	if (option->minus == 1)
		cnt += padding_u(u, len, option);
	cnt += fill_width_nbr(cnt, pad, option);
	if (option->minus == 0)
		cnt += padding_u(u, len, option);
	return (cnt);
}
