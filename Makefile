# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 09:04:16 by aducobu           #+#    #+#              #
#    Updated: 2023/05/07 09:46:32 by aducobu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = sources/main.c sources/parsing.c
SRCS_GNL = gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS = ${SRCS:.c=.o}
OBJS_GNL = ${SRCS_GNL:.c.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm-rf

${NAME}:	${OBJS} ${OBJS_GNL}
			${CC} ${CFLAGS} -o ${NAME} ${SRCS} ${SRCS_GNL}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJS_GNL}
			
fclean:		clean
			${RM} ${NAME}

re:			fclean all