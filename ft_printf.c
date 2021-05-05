/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 16:57:52 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/05 17:10:28 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		print_type(t_option *option, va_list ap)
{
	int		ret;
	int		type;

	ret = 0;
	type = option->type;
	if (type == 0)
		ret += print_char(va_arg(ap, int), option);
	else if (type == 1)
		ret += print_str(va_arg(ap, char *), option);
	return (ret);
}

void	init_option(t_option *option)
{
	option->minus = 0;
	option->zero = 0;
	option->width = 0;
	option->pre = -1;
	option->type = 0;
}

void	set_wp(char *format, t_option *option, va_list ap, int i)
{
	if (ft_isdigit(format[i]))
	{
		if (option->pre == -1)
			option->width = option->width * 10 + (format[i] - 48);
		else
			option->pre = option->pre * 10 + (format[i] - 48);
	}
	else
	{
		if (option->pre == -1)
		{
			option->width = va_arg(ap, int);
		}
		else
			option->pre = va_arg(ap, int);
	}
}

void	set_option(char *format, t_option *option, va_list ap, int i)
{
	if (format[i] == '-')
		option->minus = 1;
	else if (format[i] == '0' && option->width == 0 && option->pre == -1)
		option->zero = 1;
	else if (format[i] == '.')
		option->pre = 0;
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
			ret += print_type(option, ap);
			//print_op(option);
		}
	}
	free(option);
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int			ret;
	va_list		ap;

	va_start(ap, format);
	ret = parse((char *)format, ap);
	va_end(ap);

	return (ret);
}

int main(void)
{
	char c[] = "this is string"; // len = 14
	int n = 10;

	ft_printf("1 >%*s<\n", n, c);
	ft_printf("2 >%-*s<\n",n, c);
	ft_printf("3 >%0*.s<\n",n, c);
	ft_printf("4 >%-s<\n", c);
	ft_printf("5 >%-.s<\n", c);
	ft_printf("6 >%.s<\n", c);
	ft_printf("7 >%010.4s<\n", c);
	ft_printf("8 >%.4s<\n", c);
	ft_printf("9 >%.1s<\n", c);
	ft_printf("A >%.s<\n", c);
	ft_printf("B >%14.10s<\n", c);
	ft_printf("C >%0.100s<\n", c);
	ft_printf("D >%-.100s<\n", c);


	return (0);
}
