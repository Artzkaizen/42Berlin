# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 16:56:39 by chuezeri          #+#    #+#              #
#    Updated: 2024/09/19 14:42:23 by chuezeri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        := libft.a
SRC_DIR     := srcs
INC_DIR     := includes
SRCS        := ft_putchar.c \
               ft_swap.c \
               ft_putstr.c \
               ft_strlen.c \
               ft_strcmp.c
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS        := $(SRCS:.c=.o)

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I $(INC_DIR)
AR          := ar rcs
RM          := rm -f
MAKEFLAGS   := --no-print-directory

all: $(NAME)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re