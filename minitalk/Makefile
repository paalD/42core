# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/28 15:52:39 by dpaal             #+#    #+#              #
#    Updated: 2022/06/23 22:37:41 by dpaal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= minitalk

SERVER	:= server

CLIENT	:= client

LIBFT	:= libft.a

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -c -std=c99
RM		=	rm -rf

all: $(LIBFT) $(CLIENT) $(SERVER)

$(LIBFT):
	make -C ./Libft
	cp Libft/libft.a .
	make fclean -C ./Libft

$(CLIENT): client.c
	$(CC) client.c libft.a -o $@

$(SERVER): server.c
	$(CC) server.c libft.a -o $@

clean :
	$(RM) *.o

fclean :	clean
	$(RM) $(CLIENT)
	$(RM) $(SERVER)
	$(RM) libft.a

re :		fclean all

.PHONY: all clean fclean re
