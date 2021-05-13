/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:07:26 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/13 12:30:28 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.h"

# define TYPE "cspdiuxX%"

typedef struct	s_option
{
	int			minus;
	int			zero;
	int			width;
	int			pre;
	int			type;
}				t_option;

int				print_type(t_option *option, va_list ap);
void			set_wp(char *format, t_option *option, va_list ap, int i);
void			set_option(char *format, t_option *option, va_list ap, int i);
int				parse(char *format, va_list ap);
int				ft_printf(const char *format, ...);
int				fill_width(int len, int zero, int width, int minus);
int				print_char(int c, t_option *option);
int				check_pre(char *str, int len, int pre);
int				print_str(char *str, t_option *option);
int				check_padding(int d, int len, t_option *option);
int				fill_width_nbr(int cnt, int pad, t_option *option);
int				padding(int d, int len, int sign, t_option *option);
int				print_decimal(int d, t_option *option);
int				padding_u(unsigned int u, int len, t_option *option);
int				ft_putunbr(unsigned int n);
int				print_u(unsigned int u, t_option *option);
int				ft_putnbr_hex(unsigned int u);
int				padding_x(unsigned int u, int len, t_option *option);
int				print_x(unsigned int u, t_option *option);
int				ft_putnbr_lh(unsigned int u);
int				padding_xx(unsigned int u, int len, t_option *option);
int				print_xx(unsigned int u, t_option *option);
int				ft_putnbr_pointer(unsigned long long p);
int				padding_p(unsigned long long p, int len, t_option *option);
int				print_p(unsigned long long p, t_option *option);
int				decimal_digit(int d);
int				unsigned_digit(unsigned int u);
int				hex_digit(unsigned int u);
int				pointer_digit(unsigned long long p);
void			init_option(t_option *option);

#endif
