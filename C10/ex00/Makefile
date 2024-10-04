# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chuezeri <chuezeri@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 11:09:10 by chuezeri          #+#    #+#              #
#    Updated: 2024/10/04 11:52:59 by chuezeri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        := ft_display_file
SRC_DIR     := srcs
INC_DIR     := includes
BUILD_DIR	:= obj
SRCS        := main.c
SRCS        := $(SRCS:%=$(SRC_DIR)/%)
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

CC          := cc
CFLAGS      := -Wall -Wextra -Werror
CPPFLAGS    := -I $(INC_DIR)
RM          := rm -f
MAKEFLAGS   := --no-print-directory

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

.PHONY: all clean fclean re