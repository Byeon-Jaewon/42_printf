/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:15:42 by jbyeon            #+#    #+#             */
/*   Updated: 2021/04/29 16:17:33 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(0, &c, 1);
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
