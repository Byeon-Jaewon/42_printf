/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 12:07:26 by jbyeon            #+#    #+#             */
/*   Updated: 2021/04/29 16:16:09 by jbyeon           ###   ########.fr       */
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
	int		dot;
	int		type;
}	t_option;

void	ft_putchar(char c);
int		ft_strchr(char *s, int c);
int		ft_isdigit(int c);


#endif
