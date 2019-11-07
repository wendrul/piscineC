# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/17 15:26:40 by ede-thom          #+#    #+#              #
#    Updated: 2019/08/18 23:37:42 by ede-thom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ./main.c ./error_handling.c ./ft_split.c ./ft_strjoin.c ./int_to_text.c ./libft.c ./libft_tab.c ./parsing_itot.c ./string_operations.c 

OBJS	= ${SRCS:.c=.o}

NAME	= rush-02

RM		= rm -f

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			rm ${NAME}

.PHONY:		all clean fclean fclean
