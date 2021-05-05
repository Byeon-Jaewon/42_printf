/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:07:26 by jbyeon            #+#    #+#             */
/*   Updated: 2021/05/05 17:31:27 by jbyeon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

# define TYPE "csdiupxX%"

typedef struct		s_option
{
	int		minus;
	int		zero;
	int		width;
	int		pre;
	int		type;
}	t_option;

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_strchr(char *s, int c);
int		ft_isdigit(int c);
int		ft_strlen(char *str);
void	ft_putnbr(int n);


int		print_char(int c, t_option *option);
int		print_str(char *str, t_option *option);
int		fill_width(int len, int zero, int width);
int		check_pre(char *str, int len, int pre);



#endif
