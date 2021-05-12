/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:43:57 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/12 14:25:29 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putnbr_hex(long d)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (d < 0)
	{
		d *= -1;
		ft_putchar('-');
		ft_putnbr_hex(d);
	}
	else if (d < 16)
		ft_putchar(hex[d]);
	else
	{
		ft_putnbr_hex(d / 16);
		ft_putchar(hex[d % 16]);
	}
}

int		print_hex(int d, t_option *option)
{
	int		ret;
	int		len;

	ret = 0;
	len = hex_digit(d);

}
