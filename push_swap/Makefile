# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/04 21:24:02 by dpaal             #+#    #+#              #
#    Updated: 2022/05/20 17:33:43 by dpaal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	:= push_swap

BONUS	:= checker

SRC_DIR		:= src/
SRC_FILES	:= push_swap.c ft_atolli.c check_input.c lst_utils.c \
				swap.c push.c rotate.c reverse_rotate.c \
				sort_five.c index_lst.c \
				sort_more.c sort_more_utils.c utils.c\

SRC			:= $(addprefix $(SRC_DIR),$(SRC_FILES))

BUILD_DIR := build/
OBJS := $(SRC:%=$(BUILD_DIR)%.o)

BNS_DIR		:= bonus_src/
BNS_FILES	:= checker.c checker_utils.c check_input.c \
				ft_atolli.c ft_split.c lst_utils.c\
				bns_push.c bns_reverse_rotate.c bns_rotate.c bns_swap.c \
				str_utils.c utils.c index_lst.c\

BNS_SRC		:= $(addprefix $(BNS_DIR),$(BNS_FILES))

BNS_BUILD_DIR := build/
BNS_OBJS := $(BNS_SRC:%=$(BNS_BUILD_DIR)%.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -c
RM		=	rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $< -o $@

bonus: $(BONUS)

$(BONUS): $(BNS_OBJS)
	$(CC) $(BNS_OBJS) -o $@

$(BNS_BUILD_DIR)%.c.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $< -o $@

clean :
	$(RM) $(OBJS)
	$(RM) $(BNS_OBJS)

fclean :	clean
	$(RM) $(BUILD_DIR)
	$(RM) $(BNS_BUILD_DIR)
	$(RM) $(NAME)
	$(RM) $(BONUS)

re :		fclean all

.PHONY: all clean fclean re
