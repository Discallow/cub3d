# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asofia-g <asofia-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/04 16:15:56 by asofia-g          #+#    #+#              #
#    Updated: 2024/04/14 17:06:21 by asofia-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

# Compielr and Flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
#Because libft doesnt as main
AR = ar rcs

SCRS = ft_isalnum.c  ft_isalpha.c  ft_isascii.c  ft_isdigit.c  ft_isprint.c  ft_isspace.c\
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoil.c ft_atoi.c ft_atol.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strcmp.c \
	ft_printf.c \
	ft_printarg.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putnbr.c \
	get_next_line.c \

OBJS = $(SCRS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
