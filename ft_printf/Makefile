# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibault <thibault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 11:43:36 by thibault          #+#    #+#              #
#    Updated: 2023/07/19 17:49:43 by thibault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the librairy
NAME = libftprintf.a

# Compiling flags
FLAGS = -Wall -Wextra -Werror

# Folders
SRC_DIR		= ./srcs/
OBJ_DIR		= ./obj/
INC_DIR		= ./includes/
LIBFT_DIR	= ./../libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Source: files
SRC_FILES = ft_printf.c ft_print_csdiu.c ft_print_hex.c ft_printptr.c \
# Source: object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
# SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# all rule ("make all" ou "make" execute cette commande -> les dépendances obj et NAME sont construites)
all: obj ${NAME}

# Création du répertoire obj si celui-ci n'existe pas (flag -p)
obj:
	@mkdir -p $(OBJ_DIR)

# Compiling -> construction des fichiers obj
${OBJ}: $(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@echo "...Compiling $<"
	@gcc $(FLAGS) -I $(INC_DIR) -I $(LIBFT_DIR) -o $@ -c $<
	
$(LIBFT):
	@echo "...Compiling $(LIBFT_DIR)$<"
	make -C $(LIBFT_DIR)

# Linking
${NAME}: ${OBJ} $(LIBFT)
	@echo "Wait a sec..."
	@echo "objects files generated."
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) generated!".

# clean rule
clean:
	@echo "Cleaning libft"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "Cleaning objects"
	@rm -Rf $(OBJ_DIR)
	@echo "Objects removed!"

# fclean rule
fclean:	clean
	@echo "Full cleaning libft"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

# re rule
re:	fclean all

# phony
.PHONY: all clean fclean re



