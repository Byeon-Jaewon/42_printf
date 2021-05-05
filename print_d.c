/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 12:27:48 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/05 17:21:55 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_decimal(int d, t_option *option)
{
	int		ret;

	ret = 0;

	len = ft_strlen(str);
	if (option->minus == 1)
		ft_putnbr(d);
	if (option->pre > -1 && option->pre < len)
		ret += fill_width(option->pre, option->zero, option->width);
	if (option->pre < 0 || option->pre > len)
		ret += fill_width(len, option->zero, option->width);
	if (option->minus == 0)
		ft_putnbr(d);
	return (ret);
}
