# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pallyson <pallyson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/06 18:28:10 by pallyson          #+#    #+#              #
#    Updated: 2021/01/20 16:31:39 by pallyson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc
CFLAGS		= -c -Wall -Wextra -Werror
AR			= ar rc
RM			= rm -rf

SRCS 		=*.c

OBJ			= *.o
LIB_PATH	= ./libft
INCLUDES	= ./includes

$(NAME):
			cd $(LIB_PATH) && $(MAKE)
			$(CC) -g $(CFLAGS) $(SRCS) -I$(INCLUDES)
			ar rc $(NAME) $(OBJ) $(LIB_PATH)/*.o
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ)
			cd $(LIB_PATH) && $(MAKE) clean

fclean:		clean
			$(RM) $(NAME)
			cd $(LIB_PATH) && $(MAKE) fclean

re:			fclean all

.PHONY: clean fclean re all
