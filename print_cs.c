/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 13:47:12 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/05 17:19:45 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fill_width(int len, int zero, int width)
{
	int		ret;

	ret = 0;
	while (len < width)
	{
		if (zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		len++;
		ret++;
	}
	return (ret);
}

int		check_pre(char *str, int len, int pre)
{
	int		i;

	i = 0;
	if (pre < 0 || pre > len)
	{
		ft_putstr(str);
		return (len);
	}
	else
	{
		while (i < pre)
		{
			ft_putchar(str[i]);
			i++;
		}
		return (pre);
	}
}

int		print_char(int c, t_option *option)
{
	int		ret;

	ret = 0;
	if (option->minus == 1)
	{
		ft_putchar(c);
		ret++;
	}
	ret += fill_width(1, option->zero, option->width);
	if (option->minus == 0)
	{
		ft_putchar(c);
		ret++;
	}
	return (ret);
}

int		print_str(char *str, t_option *option)
{
	int		ret;
	int		len;

	ret = 0;
	len = ft_strlen(str);
	if (option->minus == 1)
		ret += check_pre(str, len, option->pre);
	if (option->pre > -1 && option->pre < len)
		ret += fill_width(option->pre, option->zero, option->width);
	if (option->pre < 0 || option->pre > len)
		ret += fill_width(len, option->zero, option->width);
	if (option->minus == 0)
		ret += check_pre(str, len, option->pre);
	return (ret);
}
