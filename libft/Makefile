# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbyeon <jbyeon@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/25 16:11:45 by jbyeon            #+#    #+#              #
#    Updated: 2021/05/07 14:12:12 by jbyeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libft.a

CC=gcc
CFLAGS=-Wall -Wextra -Werror
AR=ar rc
RM=rm -f

SRCS=ft_isdigit.c ft_strchr.c ft_strlen.c ft_putchar.c ft_putstr.c\
	 ft_putnbr.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(CFLAG) -c $(SRCS)
	$(AR) $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
