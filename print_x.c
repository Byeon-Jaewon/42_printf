/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 11:43:57 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/07 12:04:52 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		hex_digit(int d)
{
	int		ret;

	if (d == 0)
		ret = 1;
	else
		ret = 0;
	while (d != 0)
	{
		d /= 16;
		ret ++;
	}
	return (ret);
}

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
