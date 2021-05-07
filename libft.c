/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:15:42 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/07 15:56:23 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != c)
	{
		if (s[i] == '\0')
			return (-1);
		i++;
	}
	return (i);
}

int		ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	if (s == 0)
		return ;
	write(0, s, ft_strlen(s));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = n * (-1);
		}
		if (n > 9)
		{
			ft_putnbr(n / 10);
		}
		ft_putchar((n % 10) + '0');
	}
}
