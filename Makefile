# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbasso <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/08 09:31:26 by fbasso            #+#    #+#              #
#    Updated: 2021/02/08 09:40:21 by fbasso           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = utils1.c utils2.c utils3.c utils4.c utils5.c utils6.c \
	   utils7.c utils8.c utils9.c ft_printf.c

RM = /bin/rm -f

CC = gcc

CFLAGS = -Wall -Wextra -Werror -c

OBJS = ${SRCS:.c=.o}

%.o: %.c
		${CC} ${CFLAGS} $<

all: ${NAME}

$(NAME): ${OBJS}
		ar -rc ${NAME} ${OBJS}
		ranlib ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
