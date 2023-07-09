# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibault <thibault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 16:33:11 by tsanglar          #+#    #+#              #
#    Updated: 2023/07/09 11:41:02 by thibault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Name of the librairy
NAME = libft.a

# Compiling flags
FLAGS = -Wall -Wextra -Werror

# Folders
SRC_DIR		= ./srcs/
OBJ_DIR		= ./obj/
INC_DIR	= ./includes/

# Source: files
SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
# Source: object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Paths
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

# all rule ("make all" ou "make" execute cette commande -> les dépendances obj et NAME sont construites)
all: obj ${NAME}

# Création du répertoire obj si celui-ci n'existe pas (flag -p)
obj:
	@mkdir -p $(OBJ_DIR)

# Compiling -> construction des fichiers obj
$(OBJ): $(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@echo "...Compiling $<"
	@gcc $(FLAGS) -o $@ -c $<
	
# Linking
${NAME}: ${OBJ}
	@echo "Wait a sec..."
	@echo "Object files generated."
	@echo "Linking $@"
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) generated!".


# clean rule
clean:
	@rm -Rf $(OBJ_DIR)
	@echo "Objects removed!"

# fclean rule
fclean:	clean
	@rm -f $(NAME)
	@echo "$(NAME) removed!"

# re rule
re:	fclean all

# phony
.PHONY: all clean fclean re
