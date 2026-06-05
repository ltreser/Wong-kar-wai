# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltreser <ltreser@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 19:04:56 by ltreser           #+#    #+#              #
#    Updated: 2023/08/06 19:17:50 by ltreser          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS =  ft_atoi.c      ft_isalpha.c   ft_memchr.c   ft_strchr.c    ft_strlen.c    ft_tolower.c \
        ft_bzero.c     ft_isascii.c   ft_memcmp.c   ft_strdup.c    ft_strncmp.c   ft_toupper.c \
        ft_calloc.c    ft_isdigit.c   ft_memcpy.c   ft_strlcat.c   ft_strnstr.c \
        ft_isalnum.c   ft_isprint.c   ft_memset.c   ft_strlcpy.c   ft_strrchr.c \
        ft_substr.c    ft_strjoin.c   ft_strtrim.c  ft_split.c     ft_memmove.c   ft_itoa.c\
        ft_strmapi.c   ft_putnbr_fd.c ft_putchar_fd.c  ft_putendl_fd.c   ft_putstr_fd.c\
        ft_striteri.c
BONUSFILES := ft_lstadd_front.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
			  ft_lstnew.c ft_lstsize.c ft_lstiter.c ft_lstlast.c ft_lstmap.c
OBJS = $(SRCS:.c=.o)
BONUSOBJS := $(BONUSFILES:%.c=%.o)

FLAGS = -Wall -Werror -Wextra
CC = cc

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

bonus: $(BONUSOBJS)
	ar -rcs $(NAME) $(BONUSOBJS)

clean:
	rm -rf $(OBJS) $(BONUSOBJS)

fclean: clean
	rm -rf $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

re: fclean all

.PHONY: clean all fclean re
