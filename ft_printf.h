/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:07:26 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/10 14:32:22 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct		s_option
{
	int		minus;
	int		zero;
	int		width;
	int		pre;
	int		type;
}	t_option;

int		print_char(int c, t_option *option);
int		print_str(char *str, t_option *option);
int		fill_width(int len, int zero, int width, int minus);
int		check_pre(char *str, int len, int pre);

int		print_decimal(int d, t_option *option);
int		decimal_digit(int d);
//libft
/*
void	ft_putchar(char c);
int		ft_strchr(char *s, int c);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_putstr(char *s);
void	ft_putnbr(int n);*/

#endif
