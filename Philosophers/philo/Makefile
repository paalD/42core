# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/27 15:41:16 by dpaal             #+#    #+#              #
#    Updated: 2022/10/06 10:58:25 by dpaal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER = src/philo.h
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -rf

SRC_DIR		:= src/
SRC_FILES	:= main.c \
				error.c \
				launch.c \
				initialize.c \
				utils.c \
				libft_utils.c \
				mtx_utils.c \
				eat.c \

SRC			:= $(addprefix $(SRC_DIR),$(SRC_FILES))

BUILD_DIR = build/
OBJS = $(SRC:$(SRC_DIR)%.c=$(BUILD_DIR)%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -pthread -o $@

$(OBJS): $(BUILD_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) $(OBJS)
			$(RM) $(BUILD_DIR)

fclean:		clean
			$(RM) $(NAME)

norminette:
	@norminette $(SRCS) $(HEADER)

re:			fclean all

.PHONY: all clean fclean re