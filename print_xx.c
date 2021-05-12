/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:43:57 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/12 14:37:21 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_HEX(unsigned int u)
{
	char	*hex;
	int		ret;

	hex = "0123456789ABCDEF";
	ret = 0;
	if (u < 16)
		ret += ft_putchar(hex[u]);
	else
	{
		ret += ft_putnbr_HEX(u / 16);
		ret += ft_putchar(hex[u % 16]);
	}
	return (ret);
}

int		padding_xx(unsigned int u, int len, t_option *option)
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
		cnt += ft_putnbr_HEX(u);
	return (cnt);
}

int		print_xx(unsigned int u, t_option *option)
{
	int		len;
	int		cnt;
	int		size;
	int		pad;

	cnt = 0;
	len = hex_digit(u);
	size = check_size_u(len, option);
	pad = check_padding(1, len, option);
	if (option->minus == 1)
		cnt += padding_xx(u, len, option);
	cnt += fill_width_nbr(cnt, pad, option);
	if (option->minus == 0)
		cnt += padding_xx(u, len, option);
	return (cnt);
}
