# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-thom <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 10:20:37 by ede-thom          #+#    #+#              #
#    Updated: 2019/08/22 14:14:49 by ede-thom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS        = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS        = ${SRCS:.c=.o}
	NAME        = libft.a
	RM          = rm -f
	CFLAGS      =  -Wall -Wextra -Werror -c -Iincludes
	CC          = gcc

all : $(NAME)

%.o : %.c
	gcc -c -Iincludes $(CFLAGS) $< -o $@

${NAME} : ${OBJS}
	ar rc ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re: fclean all

PHONY:        all clean fclean re
