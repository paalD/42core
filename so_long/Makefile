# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 20:25:12 by dpaal             #+#    #+#              #
#    Updated: 2022/09/27 15:05:52 by dpaal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
CC			=	gcc
FLAGS		=	-g -Wall -Wextra -Werror
HEADER		=	src/so_long.h
MLX_HEADER	=	mlx.h
SRCS		=	src/main.c \
				src/start.c \
				src/check_map.c\
				src/init_game.c \
				src/gameplay.c \
				src/movement.c \
				gnl/get_next_line.c gnl/get_next_line_utils.c

OBJS		=	$(SRCS:%.c=%.o)
RM			=	rm -f

LIBFT	:= Libft/libft.a
PRINTF	:= printf/libftprintf.a

MLX_FLAGS	=	-I /usr/X11/include -L /usr/X11/lib -L ./mlx -lmlx -lm -lX11 -lXext -lz

$(NAME):	$(LIBFT) $(PRINTF) $(OBJS)
			@make -C ./mlx
			@$(CC) $(OBJS) $(MLX_FLAGS) $(LIBFT) $(PRINTF) -o $(NAME)

%.o:		%.c $(MLX_HEADER)
			@$(CC) $(FLAGS) -Imlx -c $< -o $@

$(LIBFT):
	@make -C ./Libft

$(PRINTF):
	@make -C ./printf

all:		$(LIBFT) $(PRINTF) $(NAME)

clean:
			$(RM) $(OBJS)
			@make clean -C ./Libft
			@make clean -C ./printf

fclean:		clean
			$(RM) $(NAME)
			@make clean -C ./mlx
			@make fclean -C ./Libft
			@make fclean -C ./printf

norminette:
	@norminette $(SRCS) $(HEADER)

re:			fclean all

.PHONY: all clean fclean re
