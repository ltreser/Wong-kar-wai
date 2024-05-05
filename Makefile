# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltreser <ltreser@student.42berlin.de>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/03 21:38:39 by ltreser           #+#    #+#              #
#    Updated: 2024/05/04 02:06:42 by ltreser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 2048

SRC = game_matrix.c main.c

SRC_DIR = src/

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

INC_DIR = include/

HEADERS = $(addprefix $(INC_DIR), 2048.h)

CC = cc

CFLAGS = -Wall -Werror -Wextra -Iinclude/ -I/usr/include -O3

LDLIBS = -lft -lncurses

LDFLAGS = -L libft -L ncurses

RM = rm -rf

LIBFT = libft/libft.a

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -I/usr/include -c  $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME): $(HEADERS) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LDFLAGS) $(LDLIBS)

clean:
	$(RM) $(OBJ)

fclean: clean
	make -C libft fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: re fclean clean all

