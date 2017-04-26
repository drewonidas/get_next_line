# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdlamini <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/21 12:36:21 by mdlamini          #+#    #+#              #
#    Updated: 2016/11/21 18:40:11 by mdlamini         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Test

SRC = get_next_line.c main.c

OBJ = $(SRC:.c=.o)

OPTS = -Wall -Wextra -Werror

LIB = ../libft/

$(NAME):
	@gcc -o $(NAME) $(SRC) $(OPTS) -I../libft/includes/ -L../libft/
	@clear
	@echo "---==== test built ====---"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "---==== clean ====---"

fclean: clean
	@rm -f $(NAME)

re: fclean all

lean: all clean
