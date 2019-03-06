# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsebasti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/19 19:01:27 by qsebasti          #+#    #+#              #
#    Updated: 2019/03/06 11:01:22 by squiquem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = fillit

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRC = main.c \
	  ft_read.c \
	  ft_check.c \
	  input.c \
	  make.c \
	  tetri.c \
	  solve.c

OBJ = $(SRC:.c=.o)

INC = -I .

LIB = libft/

LIBFTA = -L ./libft/ -lft

RM = /bin/rm -f

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	$(CC) $(CFLAG) -o $@ $^ $(INC) $(LIBFTA)

%.o:%.c
	$(CC) $(CFLAGS) -c $< $(INC)

clean:
	make fclean -C $(LIB)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
