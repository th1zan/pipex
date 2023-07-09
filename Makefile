# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibault <thibault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2023/07/09 12:22:31 by thibault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# ==== External folders and libraries ==== #
INC_DIR     = ./includes/
LIBFT_DIR   = ./libft/
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF_DIR  = ./printf/
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# ==== Project's folders ==== #
SRC_DIR     = ./srcs/
OBJ_DIR     = ./obj/

# ==== Project's files ==== #
SRC_FILES       = pipex.c
SRCS            = $(addprefix $(SRC_DIR), $(SRC_FILES))

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
#	@echo "==== Compiling libft ===="
#	@$(MAKE) -C $(LIBFT_DIR)
	@echo "==== Compiling libftprintf ===="
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "==== Compiling $(NAME) ===="
#	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(PRINTF) #$(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(PRINTF)
	@echo "==== $(NAME) is ready! ===="
	@cat "$(TEMPLATE)"

all: $(NAME)

clean:
#	@echo "==== Cleaning libft ===="
#	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "==== Cleaning libftprintf ===="
	@$(MAKE) clean -C $(PRINTF_DIR)
	@echo "==== Cleaning objects ===="
	@$(RM_FILE) $(OBJ_DIR)

fclean: clean
#	@echo "==== Full cleaning libft ===="
#	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "==== Full cleaning libftprintf ===="
	@$(MAKE) fclean -C $(PRINTF_DIR)
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
