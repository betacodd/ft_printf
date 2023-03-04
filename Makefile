# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elevy <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/12 16:01:43 by elevy             #+#    #+#              #
#    Updated: 2022/12/21 11:47:01 by elevy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRSRC		= ./src/

DIRINC		= ./include/

DIRLIB		= ./libft/

DIROBJ		= ./objs/

SRC			= ft_printf ft_putchar ft_putstr ft_putnbr ft_voidhexa ft_majhexa ft_putnbr_uns ft_minhexa

SRCS		= $(addprefix ${DIRSRC}, $(addsuffix .c, ${SRC}))

HEAD		= ./includes/

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

NAMELFT		= libft.a

CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib

CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -c -I${DIRINC} -I${DIRLIB} $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd ${DIRLIB} && ${MAKE} && cp -v ${NAMELFT} ../${NAME}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

main:		${NAME}
			${CC} -I ${DIRINC} -I ${DIRLIB} ${NAME} main.c
all:		$(NAME)

clean:
			${RM} ${OBJS}
			cd ${DIRLIB} && ${MAKE} clean

fclean:		clean
			${RM} $(NAME)
			cd ${DIRLIB} && ${MAKE} fclean

re:		fclean all

.PHONY:		all clean fclean re
