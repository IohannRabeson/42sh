# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irabeson <irabeson@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 10:49:54 by irabeson          #+#    #+#              #
#    Updated: 2014/02/09 21:36:46 by irabeson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g
INCLUDES = -I./includes/
SRC_DIR = ./src
BUILD_DIR = ./builds
OBJS = $(addprefix $(BUILD_DIR)/, $(SRC:.c=.o))
NAME = libft
CL_ID = \033[1;32m
CL_NO = \033[0m
CL_RM = \033[0;31m

TARGET = $(NAME).a
SRC = 								\
		ft_error.c					\
		$(SRC_PRINT)				\
		$(SRC_STRING)				\
		$(SRC_MEMORY)				\
		$(SRC_LIST)					\
		$(SRC_MINMAX)				\
		$(SRC_BTREE)				\
		$(SRC_STR_ARRAY)			\
		$(SRC_STR_BUF)				\
		$(SRC_GETS)					\
		$(SRC_FORMAT)

SRC_FORMAT =						\
		ft_format_align.c			\
		ft_format_csuffix.c

SRC_GETS =							\
		ft_gnl.c					\
		ft_getopt_access.c			\
		ft_getopt.c					\
		ft_getopt_parse.c			\
		ft_get_next_line.c			\
		ft_go_flag_destroy.c		\
		ft_go_flag_init.c			\
		ft_go_init_functions2.c		\
		ft_go_init_functions.c

SRC_MINMAX =						\
		ft_minmax_int.c				\
		ft_minmax_uint.c			\
		ft_minmax_long.c			\
		ft_minmax_ulong.c			\
		ft_minmax_llong.c			\
		ft_minmax_ullong.c			\
		ft_minmax_size_t.c

SRC_BTREE =							\
		ft_btree_contains.c			\
		ft_btree_copy.c				\
		ft_btree_clear.c			\
		ft_btree_destroy.c			\
		ft_btree_empty.c			\
		ft_btree_erase.c			\
		ft_btree_find.c				\
		ft_btree_init.c				\
		ft_btree_insert.c			\
		ft_btree_iter.c				\
		ft_btree_minmax.c			\
		ft_btree_node_access.c		\
		ft_btree_node.c				\
		ft_btree_node_iter.c		\
		ft_btree_node_query.c		\
		ft_btree_remove.c			\
		ft_btree_size.c				\
		ft_btree_transfer_if.c

SRC_LIST =							\
		ft_list.c					\
		ft_list_access.c			\
		ft_list.c					\
		ft_list_modifier.c			\
		ft_list_erase_if.c			\
		ft_list_foreach.c			\
		ft_list_node.c				\
		ft_list_push_pop.c			\
		ft_list_query.c

SRC_STR_ARRAY =						\
		ft_str_array.c				\
		ft_str_array_from.c			\
		ft_str_array_foreach.c		\
		ft_str_array_append.c		\
		ft_str_array_find.c

SRC_STR_BUF =						\
		ft_str_buf.c				\
		ft_str_buf_insert.c			\
		ft_str_buf_replace.c		\
		ft_str_buf_pop.c			\
		ft_str_buf_erase.c			\
		ft_str_buf_access.c			\
		ft_str_buf_app.c			\
		ft_str_buf_get.c			\
		ft_str_buf_clone.c			\
		ft_str_buf_rw.c

SRC_MEMORY =						\
		ft_bzero.c					\
		ft_memalloc.c				\
		ft_realloc.c				\
		ft_memccpy.c				\
		ft_memchr.c					\
		ft_memcmp.c					\
		ft_memcpy.c					\
		ft_memdel.c					\
		ft_memmove.c				\
		ft_memset.c

SRC_STRING =						\
		ft_atoi.c					\
		ft_itoa.c					\
		ft_lltoa.c					\
		ft_ltoa.c					\
		ft_match.c					\
		ft_strfind.c				\
		ft_strrep.c					\
		ft_strrepn.c				\
		ft_isalnum.c				\
		ft_isalpha.c				\
		ft_isascii.c				\
		ft_isdigit.c				\
		ft_isprint.c				\
		ft_strapp.c					\
		ft_strcat.c					\
		ft_strccpy_it.c				\
		ft_strchr.c					\
		ft_strclr.c					\
		ft_strcmp.c					\
		ft_strcpy.c					\
		ft_strcpy_it.c				\
		ft_strdel.c					\
		ft_strdup.c					\
		ft_strequ.c					\
		ft_striter.c				\
		ft_striteri.c				\
		ft_strjoin.c				\
		ft_strlcat.c				\
		ft_strlcmp.c				\
		ft_strlen.c					\
		ft_strlncmp.c				\
		ft_strmap.c					\
		ft_strmapi.c				\
		ft_strnapp.c				\
		ft_strncat.c				\
		ft_strnchr.c				\
		ft_strncmp.c				\
		ft_strncpy.c				\
		ft_strndup.c				\
		ft_strnequ.c				\
		ft_strnew.c					\
		ft_strnstr.c				\
		ft_strrchr.c				\
		ft_strsplit.c				\
		ft_strsplits.c				\
		ft_strsplit_list.c			\
		ft_strstr.c					\
		ft_strsub.c					\
		ft_strtrim.c				\
		ft_tolower.c				\
		ft_toupper.c				\
		ft_uitoa.c					\
		ft_ulltoa.c					\
		ft_ultoa.c

SRC_PRINT = 						\
		ft_putchar.c				\
		ft_putchar_fd.c				\
		ft_putstr.c					\
		ft_putstr_fd.c				\
		ft_putstrn.c				\
		ft_putstrn_fd.c				\
		ft_putendl.c				\
		ft_putendl_fd.c				\
		ft_putl.c					\
		ft_putl_fd.c				\
		ft_putll.c					\
		ft_putll_fd.c				\
		ft_putnbr.c					\
		ft_putnbr_fd.c				\
		ft_putui.c					\
		ft_putui_fd.c				\
		ft_putul.c					\
		ft_putul_fd.c				\
		ft_putull.c					\
		ft_putull_fd.c

all: $(NAME) 

$(NAME): $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJS)
	@echo " + Archiving $(CL_ID)$@$(CL_NO)"
	@ar -rs $(TARGET) $(OBJS)

clean:
	@echo " - removing object files"
	@rm -f $(OBJS)

fclean: clean
	@echo " - removing $(CL_RM)$(TARGET)$(CL_NO)"
	@rm -f $(TARGET)

re: fclean $(NAME)

$(addprefix $(BUILD_DIR)/, %.o): $(addprefix $(SRC_DIR)/, %.c)
	@echo " + Compiling $(CL_ID)$^$(CL_NO)"
	@$(CC) $(INCLUDES) $(CFLAGS) -o $@ -c $<

.PHONY: directories

$(BUILD_DIR):
	@echo " + Creating $(COL_ID)directory$(COL_NO)"
	@mkdir -p $(BUILD_DIR)
