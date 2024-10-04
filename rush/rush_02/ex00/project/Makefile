# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/11 14:37:34 by alneuman          #+#    #+#              #
#    Updated: 2024/09/15 22:47:08 by chuezeri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= rush-02
SRC_DIR		:= src
BUILD_DIR	:= obj
INC_DIR		:= include
SRCS		:= dict_init.c \
			   dict_ops.c \
			   main.c \
			   put_nums.c \
			   read_file.c \
			   utils.c \
			   validate.c
SRCS		:= $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= -I $(INC_DIR)
RM			:= rm -f
MAKEFLAGS	:= --no-print-directory

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re
