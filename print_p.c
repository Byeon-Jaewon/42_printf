/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:40:03 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/13 11:40:06 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnbr_pointer(unsigned long long p)
{
	char	*hex;
	int		ret;

	hex = "0123456789abcdef";
	ret = 0;
	if (p < 16)
		ret += ft_putchar(hex[p]);
	else
	{
		ret += ft_putnbr_pointer(p / 16);
		ret += ft_putchar(hex[p % 16]);
	}
	return (ret);
}

int		padding_p(unsigned long long p, int len, t_option *option)
{
	int		cnt;

	cnt = ft_putstr("0x");
	if (option->pre > len || option->pre >= 0)
	{
		while (len < option->pre)
		{
			cnt += ft_putchar('0');
			len++;
		}
	}
	if (p == 0 && option->pre == 0)
	{
		if (option->width == 0)
			return (cnt);
	}
	else
		cnt += ft_putnbr_pointer(p);
	return (cnt);
}

int		print_p(unsigned long long p, t_option *option)
{
	int		len;
	int		cnt;
	int		pad;

	cnt = 0;
	len = pointer_digit(p);
	if (option->pre == 0 && p == 0)
		pad = 2;
	else
		pad = check_padding(16, len, option);
	if (option->minus == 1)
		cnt += padding_p(p, len, option);
	cnt += fill_width_nbr(cnt, pad, option);
	if (option->minus == 0)
		cnt += padding_p(p, len, option);
	return (cnt);
}
