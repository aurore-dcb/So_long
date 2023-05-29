# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 09:04:16 by aducobu           #+#    #+#              #
#    Updated: 2023/05/29 17:41:00 by aducobu          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS =	sources/main.c \
		sources/parsing.c \
		sources/parsing2.c \
		sources/create_list.c \
		sources/utils.c \
		sources/list_to_tab.c \
		sources/check_path.c \
		sources/frees.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -Lminilibx-linux -lmlx -lXext -lX11 -lm -lz
RM = rm -rf

INCLUDE =  -I./mlx

all:		${NAME}

libft/libft.a:
			make -C libft

${NAME}:	${OBJS} libft/libft.a
			${CC} ${CFLAGS} ${INCLUDE} -o ${NAME} ${SRCS} -Llibft -lft

clean:
			make -C libft clean
			${RM} ${OBJS}
			
fclean:		clean
			make -C libft fclean
			${RM} ${NAME}

re:			fclean all