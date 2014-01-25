#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2014/01/21 19:04:04 by irabeson          #+#    #+#             *#
#*   Updated: 2014/01/25 19:24:01 by irabeson         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
CFLAGS = -Werror -Wextra -Wall -g
TARGET = ft_minishell2
SRC_DIR = ./src
INCLUDE_DIR = ./include
BUILD_DIR = ./builds
LIBFT_DIR = ../libft

SRC =			main.c						\
				app.c						\
				app_controls.c				\
				app_op.c					\
				app_run.c					\
				app_lexems.c				\
				cmd.c						\
				cmd_exec.c					\
				cmd_is.c					\
				cmd_error.c					\
				cmd_exec_file.c				\
				cmd_builder.c				\
				cmd_builder_setup_params.c	\
				cmd_builder_setup_op.c		\
				$(SRC_ENV)					\
				$(SRC_UTILS)				\
				$(SRC_PARSER)

SRC_UTILS =		path_is.c				\
				path_is_readable.c		\
				path_can.c				\
				path_concat.c			\
				path_exists.c
				
SRC_ENV =		env.c					\
				env_it.c				\
				env_var.c				\
				env_modifier.c			\
				env_access.c			\
				env_get_values.c		\
				env_copy.c

SRC_PARSER =	parser.c				\
		   		parser_add.c			\
		   		parser_run.c			\
		   		parser_load.c			\
		   		parser_matrix.c			\
		   		parser_mat_row.c		\
		   		parser_mat_row_kv.c		\
				lexem.c					\
				lexem_get_text.c		\
				lexem_is.c				\
				lexem_put.c

COLOR_ID = \033[1;32m
COLOR_NO = \033[0m
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/includes/
LIB_LINKS = -L$(LIBFT_DIR) -lft

all: $(BUILD_DIR) ft $(TARGET)

$(TARGET): $(OBJS)
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
	@make --silent -C $(LIBFT_DIR)
