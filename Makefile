# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/06 15:41:50 by jbyeon            #+#    #+#              #
#    Updated: 2021/05/06 15:51:22 by jbyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

SRCS		= ./ft_printf.c ./libft.c\
			  ./print_cs.c ./print_d.c
OBJS		= $(SRCS:.c=.o)
INCS		= .
AR=ar rc
RM=rm -f
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME) :
	$(CC) $(CFLAG) -c $(SRCS)
	$(AR) $(NAME) $(OBJS)

all : $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_B)

fclean: clean
	$(RM) $(NAME)

re : fclean all
