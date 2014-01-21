#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2014/01/21 19:04:04 by irabeson          #+#    #+#             *#
#*   Updated: 2014/01/21 22:47:27 by irabeson         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
CFLAGS = -Werror -Wextra -Wall -g
TARGET = ft_minishell2
SRC_DIR = ./src
INCLUDE_DIR = ./include
BUILD_DIR = ./builds
LIBFT_DIR = ../libft

SRC_UTILS = str_array.c

SRC =		main.c			\
			error.c			\
			env.c			\
			env_it.c		\
			env_var.c		\
			env_modifier.c	\
			env_access.c	\
			env_copy.c		\
			app.c			\
			$(SRC_UTILS)

COLOR_ID = \033[1;32m
COLOR_NO = \033[0m
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/includes/
LIB_LINKS = -L$(LIBFT_DIR) -lft

all: $(TARGET)

$(TARGET): ft $(BUILD_DIR) $(OBJS)
	@echo " - Building $(COLOR_ID)$(TARGET)$(COLOR_NO)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LIB_LINKS)

$(addprefix $(BUILD_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c)
	@echo " - Building $(COLOR_ID)$(<:.c=.o)$(COLOR_NO)..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ $(LIB_LINKS)
re: fclean $(TARGET)
	
clean:
	@echo " - Removing objects files:"
	@rm -fr $(OBJS)

fclean: clean
	@echo " - Removing $(COLOR_ID)$(TARGET)$(COLOR_NO)..."
	@rm -rf $(TARGET)

$(BUILD_DIR):
	@echo " - Creating build directory '$(COLOR_ID)$(BUILD_DIR)$(COLOR_NO)'..."
	@mkdir $(BUILD_DIR)

ft:
	make -C $(LIBFT_DIR)
