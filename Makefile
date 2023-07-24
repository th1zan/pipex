# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibault <thibault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/20 17:58:32 by ebennace          #+#    #+#              #
#    Updated: 2023/07/24 11:03:08 by thibault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# ==== External folders and libraries ==== #
INC_DIR     = ./includes/
LIBFT_DIR   = ./libft/
LIBFT		= $(LIBFT_DIR)/libft.a
PRINTF_DIR  = ./ft_printf/
PRINTF		= $(PRINTF_DIR)/libftprintf.a

# ==== Project's folders ==== #
SRC_DIR     = ./srcs/
OBJ_DIR     = ./obj/

# ==== Project's files ==== #
SRC_FILES       = pipex.c
SRCS            = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS 			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# ==== Template ==== #
TEMPLATE = srcs/header/pipex_header.txt
# TEMPLATE = 

# ==== Debug && Leak ==== #
SANITIZE       = -fsanitize=address
LEAKS          = -fsanitize=leak
DEBUGGER       = lldb

# ==== Remove ==== #
RM_FILE = /bin/rm -rf

# === Creating directorie === #
obj:
	@mkdir -p $(OBJ_DIR)

# ==== Compiling ==== #
CC              ?= gcc
FLAGS           = -g3
FLAGS           += -Wall -Werror -Wextra
FLAGS           += $(SANITIZE)
MAKE            = make -s

# === Convert all .c to .o with flags and header === # 

all: obj $(NAME)

${OBJS}: $(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@echo "...Compiling $<"
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@echo "==== Compiling libftprintf ===="
	@$(MAKE) -C $(PRINTF_DIR)
	@echo "==== Compiling $(NAME) ===="
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(PRINTF) $(LIBFT)
	@echo "==== $(NAME) is ready! ===="
	@cat "$(TEMPLATE)"

clean:
	@echo "==== Cleaning libftprintf ===="
	@$(MAKE) clean -C $(PRINTF_DIR)
	@echo "==== Cleaning objects ===="
	@$(RM_FILE) $(OBJ_DIR)

fclean: clean
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
