# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agoodwin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/15 19:34:10 by agoodwin          #+#    #+#              #
#    Updated: 2019/08/21 19:03:43 by ede-thom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	./srcs/main.c \
			./srcs/logic.c \
			./srcs/errors.c \
			./srcs/ft_split.c\
			./srcs/lib_tab.c \
			./srcs/map_parsing.c \
			./srcs/read_file.c \
			./srcs/ft_atoi.c

OBJS	= ${SRCS:.c=.o}

INCS	= headers

NAME	= bsq

LIBC	= ar rc

LIBR	= ranlib

CC		= gcc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} -o ${NAME}

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I ${INCS}

clean:
			${RM} ${OBJS}

fclean:			clean
			${RM} ${NAME}

re:				fclean all

good:			all clean

.PHONY:			all clean fclean re .c.o
