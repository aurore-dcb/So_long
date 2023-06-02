# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aducobu <aducobu@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/07 09:04:16 by aducobu           #+#    #+#              #
#    Updated: 2023/06/02 15:37:48 by aducobu          ###   ########.fr        #
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
		sources/frees.c \
		sources/init_loop.c \
		sources/display_map.c

OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -Lminilibx-linux  #-lm -lz
MLX_FLAGS = -lmlx -lXext -lX11
RM = rm -rf

LIBFT_DIR	= libft
LIBFT_LIB	= libft/libft.a
MLX_DIR		= minilibx-linux
MLX_LIB		= minilibx-linux/libmlx_Linux.a

all:		${NAME}

libft/libft.a:
			make -C libft

minilibx-linux/libmlx_Linux.a:
			make -C minilibx-linux

${NAME}:	${OBJS} libft/libft.a minilibx-linux/libmlx_Linux.a
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT_LIB} ${MLX_LIB} ${MLX_FLAGS} #-Llibft -lft

clean:
			${RM} ${OBJS}
			make -C libft clean
			make -C minilibx-linux clean
			
fclean:		clean
			${RM} ${NAME}
			make -C libft fclean

re:			fclean all
			make -C ${LIBFT_DIR} re
			make -C ${MLX_DIR} re