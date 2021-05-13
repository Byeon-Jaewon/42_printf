/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 14:04:33 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/13 11:55:20 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(int n)
{
	int		ret;

	ret = 0;
	if (n == -2147483648)
	{
		ft_putstr("2147483648");
		return (10);
	}
	else
	{
		if (n < 0)
			n = n * (-1);
		if (n > 9)
		{
			ret += ft_putnbr(n / 10);
		}
		ret += ft_putchar((n % 10) + '0');
	}
	return (ret);
}
