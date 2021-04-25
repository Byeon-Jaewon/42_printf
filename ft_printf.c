/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:44:42 by jbyeon            #+#    #+#             */
/*   Updated: 2021/04/25 15:58:25 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int		parse(const char *str)
{
	while (*str != '\0')
	{

	}
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;

	va_start(ap, format);
	printf("format = %s\n", format);
	int num = va_arg(ap, int);
	printf("%d\n", num);
	va_end(ap);

}

int		main()
{
	ft_printf("hello %d", 13);
	ft_printf("1", 10, 20);
	ft_printf("3", 10, 20, 30);
}
