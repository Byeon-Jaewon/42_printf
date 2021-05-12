/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:07:26 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/12 14:37:42 by jbyeon           ###   ########.fr       */
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
int		padding(int d, int len, int sign, t_option *option);
int		fill_width_nbr(int cnt, int pad, t_option *option);
int		check_padding(int d, int len, t_option *option);
int		decimal_digit(int d);
int		check_size(int d, t_option *option);

int		unsigned_digit(unsigned int u);
int		ft_putunbr(unsigned int n);
int		padding_u(unsigned int u, int len, t_option *option);
int		check_size_u(int len, t_option *option);
int		print_uint(unsigned int u, t_option *option);

int		hex_digit(unsigned int d);
int		ft_putnbr_hex(unsigned int u);
int		padding_x(unsigned int u, int len, t_option *option);
int		print_x(unsigned int u, t_option *option);

int		ft_putnbr_HEX(unsigned int u);
int		padding_xx(unsigned int u, int len, t_option *option);
int		print_xx(unsigned int u, t_option *option);


#endif
