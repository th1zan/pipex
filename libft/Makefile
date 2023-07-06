# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsanglar <tsanglar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 16:33:11 by tsanglar          #+#    #+#              #
#    Updated: 2023/07/06 16:42:40 by tsanglar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR		= ./srcs
BUILD_DIR	= ./build
SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c \
ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c\
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f 

.c.o:  
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
	${CC} ${CFLAGS} -c ${SRCS}
	ar rc ${NAME} ${OBJS} libft.h

all:        ${NAME}

clean:
	${RM} $(BUILD_DIR)

fclean:    clean
	${RM} ${NAME}

re:         fclean all

.PHONY: all clean fclean re