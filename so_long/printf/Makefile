# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpaal <dpaal@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 13:48:45 by dpaal             #+#    #+#              #
#    Updated: 2022/03/15 11:50:19 by dpaal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printf.c ft_putchar.c ft_putstr.c ft_putint.c ft_putu.c ft_putx.c ft_put_capx.c \
		ft_putp.c ft_strlen.c ft_itoa.c

OBJS = ${SRCS:.c=.o}

NAME	=	libftprintf.a
CC		=	gcc
RM		=	rm -f
CFLAGS	=	-Wall -Wextra -Werror -c
AR		=	ar rcs

all :		$(NAME)

$(NAME):	$(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS) :	$(SRCS)
	$(CC) $(CFLAGS) $(SRCS)

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re :		fclean all

.PHONY: all clean fclean re
