# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/20 03:41:16 by ede-thom          #+#    #+#              #
#    Updated: 2019/08/20 03:48:45 by ede-thom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c display_file.c error_handling.c

OBJS	= ${SRCS:.c=.o}

NAME	= ft_display_file

CFLAGS	= -Werror -Wall -Wextra

CC		= gcc

RM		= rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean
			${NAME}

.PHONY:		all clean fclean re 
