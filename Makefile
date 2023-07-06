# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2023/07/06 16:42:40 by tsanglar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# ==== Folders ==== #
SRC_DIR     = ./srcs/
OBJ_DIR     = ./obj/
INC_DIR     = ./includes/
LIBFT_DIR   = ./libft/
PRINTF_DIR  = ./printf/srcs/

# === Files === #
PRINTF_FILES    = ft_printf.c ft_print_csdiu.c ft_print_hex.c ft_printptr.c
SRC_FILES       = pipex.c
SRCS            = $(addprefix $(SRC_DIR), $(SRC_FILES)) $(addprefix $(PRINTF_DIR), $(PRINTF_FILES))
LIBFT           = $(LIBFT_DIR)/libft.a

# ==== Template ==== #
TEMPLATE = srcs/header/pipex_header.txt

# ==== Debug && Leak ==== #
SANITIZE       = -fsanitize=address
LEAKS          = -fsanitize=leak
DEBUGGER       = lldb

# ==== Remove ==== #
RM_FILE = /bin/rm -rf

# ==== Objet && compiling ==== #
OBJS            = $(SRCS:.c=.o)
CC              ?= gcc
FLAGS           = -g3
FLAGS           += -Wall -Werror -Wextra
FLAGS           += $(SANITIZE)
MAKE            = make -s

# === Convert all .c to .o with flags and header === # 
%.o : %.c
			@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "==== Compiling libft ===="
	@$(MAKE) -C $(LIBFT_DIR)
	@echo "==== Compiling $(NAME) ===="
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "==== $(NAME) is ready! ===="
	@cat "$(TEMPLATE)"

all: $(NAME)

clean:
	@echo "==== Cleaning libft ===="
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "==== Cleaning objects ===="
	@$(RM_FILE) $(OBJ_DIR)

fclean: clean
	@echo "==== Full cleaning libft ===="
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "==== Full cleaning $(NAME) ===="
	@$(RM_FILE) $(NAME)

debug: FLAGS += $(SANITIZE)
debug: $(NAME)
	@echo "==== Debugging with $(DEBUGGER) ===="
	@$(DEBUGGER) $(NAME)
	@cat "$(TEMPLATE)"

sanitize: FLAGS += $(SANITIZE)
sanitize: $(NAME)
	@echo "==== Sanitizing $(NAME) ===="
	@cat "$(TEMPLATE)"

leak: FLAGS += $(LEAKS)
leak: $(NAME)
	@echo "==== Leak checking $(NAME) ===="
	@cat "$(TEMPLATE)"

re: fclean all

.PHONY: all clean fclean debug sanitize leak re
