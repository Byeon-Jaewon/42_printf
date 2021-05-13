/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 13:39:03 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/13 11:36:14 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int		print_u(unsigned int u, t_option *option)
{
	int		len;
	int		cnt;
	int		pad;

	cnt = 0;
	len = unsigned_digit(u);
	pad = check_padding(1, len, option);
	if (option->minus == 1)
		cnt += padding_u(u, len, option);
	cnt += fill_width_nbr(cnt, pad, option);
	if (option->minus == 0)
		cnt += padding_u(u, len, option);
	return (cnt);
}
