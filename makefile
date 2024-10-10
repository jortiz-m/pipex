# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jortiz-m <jortiz-m@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 12:55:25 by jortiz-m          #+#    #+#              #
#    Updated: 2024/10/10 12:39:02 by jortiz-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= pipex
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra -g
RM		= rm -rf

LIBFT_DIR		= lib/libft
LIBFT_FILE		= $(LIBFT_DIR)/libft.a

MAKE_LIB		= make --no-print-directory -C

PIPEX_SRC	= pipex.c \
            process.c \
            pipex_utils.c \
            check_cmd.c \
            check_fd.c \
            exec.c \
            matrix_utils.c \
            create.c


PIPEX_OBJ = $(addprefix obj/, $(PIPEX_SRC:.c=.o))

all: $(NAME)

$(LIBFT_FILE):
	@$(MAKE_LIB) $(LIBFT_DIR)

obj/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(PIPEX_OBJ) $(LIBFT_FILE)
	@$(CC) $(CFLAGS) -o $@ $^ -L $(LIBFT_DIR)
	@echo $(NAME) compiled!

clean:
	@$(RM) obj
	@$(RM) $(LIBFT_DIR)/*.o
	@$(RM) $(LIBFT_DIR)/.DS_Store
	@$(RM) $(LIBFT_DIR)/.vscode
	@echo Objects removed

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_FILE)
	@$(RM) .vscode
	@$(RM) .DS_Store
	@echo Executable removed

re: fclean all

.PHONY: all clean fclean re