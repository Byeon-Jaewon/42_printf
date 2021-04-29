/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:57:52 by jbyeon            #+#    #+#             */
/*   Updated: 2021/04/29 16:57:55 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void	print_op(t_option *option)
{
	printf("\n\nminus : %d\n", option->minus);
	printf("zero : %d\n", option->zero);
	printf("width : %d\n", option->width);
	printf("dot : %d\n", option->dot);
	printf("type : %d", option->type);
}

void	init_option(t_option *option)
{
	option->minus = 0;
	option->zero = 0;
	option->width = 0;
	option->dot = -1;
	option->type = 0;
}

void	set_wp(char *format, t_option *option, va_list ap, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (option->dot == -1)
			option->width = (option->width * 10) + (format[i] - 48);
		else
			option->dot = (option->dot * 10) + (format[i] - 48);
	}
	else
	{
		if (option->dot == -1)
		{
			option->width = va_arg(ap, int);
		}
		else
			option->dot = va_arg(ap, int);
	}
}

void	set_option(char *format, t_option *option, va_list ap, int i)
{
	if (format[i] == '-')
		option->minus = 1;
	else if (format[i] == '0')
		option->zero = 1;
	else if (format[i] == '.')
		option->dot = 0;
	else if (ft_isdigit(format[i]) || format[i] == '*')
		set_wp(format, option, ap, i);
}

int		parse(char *format, va_list ap)
{
	int			i;
	int			ret;
	t_option	*option;

	i = 0;
	ret = 0;
	if (!(option = malloc(sizeof(t_option))))
		return (-1);
	while (format[i] != '\0')
	{
		while (format[i] != '%' && format[i] != '\0')
		{
			ft_putchar(format[i++]);
			ret++;
		}
		if (format[i] == '%')
		{
			init_option(option);
			i++;
			while (format[i] != '\0' && ft_strchr(TYPE, format[i]) == -1)
			{
				set_option(format, option, ap, i);
				i++;
			}
			if (ft_strchr(TYPE, format[i]) != -1)
				option->type = ft_strchr(TYPE, format[i++]);
			print_op(option);
		}
	}
	free(option);
	return (ret);


int		ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = parse((char *)format, ap);
	va_end(ap);

	return (ret);
}

int	main()
{
	int		a;

	a = ft_printf("asdf\n%0*X, %-0.2d",2,3,5);
	printf("\nret = %d",a);

