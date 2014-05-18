#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2014/01/21 19:04:04 by irabeson          #+#    #+#             *#
#*   Updated: 2014/05/18 04:17:50 by irabeson         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

CC = gcc
MODE=release
CMODE = -O3
ifeq ($(MODE), debug)
CMODE = -g
endif
CFLAGS = -Werror -Wextra -Wall $(CMODE)
TARGET = ft_minishell3
SRC_DIR = ./src
INCLUDE_DIR = ./include
BUILD_DIR = ./builds
LIBFT_DIR = ./libft

SRC =			main.c						\
				app.c						\
				app_init.c					\
				app_kill.c					\
				app_controls.c				\
				app_op.c					\
				app_cd.c					\
				app_run.c					\
				app_process_line.c			\
				app_process_cmd.c			\
				app_lexems.c				\
				app_complete_bin_path.c		\
				app_set.c					\
				lexems_preprocess.c			\
				lexems_find_next.c			\
				syntax.c					\
				syntax_check.c				\
				syntax_build.c				\
				build_cmd_imp.c				\
				builtins.c					\
				builtins_find.c				\
				builtins_add.c				\
				builtins_load.c				\
				builtin.c					\
				cmd.c						\
				cmd_set_files.c				\
				cmd_add_arg.c				\
				cmd_exec.c					\
				cmd_exec_chain.c			\
				cmd_error.c					\
				$(SRC_ENV)					\
				$(SRC_UTILS)				\
				$(SRC_PARSER)				\
				$(SRC_BUILTINS)				\
				$(SRC_TERMCAPS)

SRC_BUILTINS =	bt_exit.c				\
				bt_cd.c					\
				bt_env.c				\
				bt_unsetenv.c			\
				bt_setenv.c				\
				bt_help.c


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
				parser_add_kw.c			\
				parser_run.c			\
				parser_load.c			\
				parser_matrix.c			\
				parser_mat_access.c		\
				parser_mat_row.c		\
				parser_mat_row_kv.c		\
				lexem.c					\
				lexem_get_text.c		\
				lexem_is.c				\
				lexem_put.c

SRC_TERMCAPS =	textedit.c					\
				textedit_multiline.c		\
				textedit_display.c			\
				textedit_move.c				\
				textedit_move_word.c		\
				textedit_replace.c			\
				textedit_get.c				\
				textedit_goto.c				\
				histo.c						\
				cursor.c					\
				cursor_delete.c				\
				key.c						\
				key_cmp.c					\
				key_query.c					\
				keymapper.c					\
				terminal_exec.c				\
				terminal_query.c			\
				terminal.c

ifeq ($(MODE), debug)
COLOR_ID = \033[0;32m
else
COLOR_ID = \033[0;34m
endif
COLOR_NO = \033[0m
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))
SRCS = $(addprefix $(SRC_DIR)/, $(SRC))
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)/includes/
LIB_LINKS = -L$(LIBFT_DIR) -lft -ltermcap

all: $(BUILD_DIR) ft $(TARGET)

$(TARGET): $(OBJS)
	@echo " - Building $(COLOR_ID)$(TARGET)$(COLOR_NO)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(TARGET) $(LIB_LINKS)

$(addprefix $(BUILD_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c)
	@echo " - Building $(COLOR_ID)$(@:.c=.o)$(COLOR_NO)..."
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

re: fclean $(BUILD_DIR) ft $(TARGET)

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
