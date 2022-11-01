# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:09:36 by lray              #+#    #+#              #
#    Updated: 2022/11/02 00:04:16 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = \
	./ft_atoi.c \
	./ft_bzero.c \
	./ft_calloc.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isascii.c \
	./ft_isdigit.c \
	./ft_isprint.c \
	./ft_itoa.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_memset.c \
	./ft_putchar_fd.c \
	./ft_putstr_fd.c \
	./ft_split.c \
	./ft_strchr.c \
	./ft_strdup.c \
	./ft_striteri.c \
	./ft_strjoin.c \
	./ft_strlcat.c \
	./ft_strlcpy.c \
	./ft_strlen.c \
	./ft_strmapi.c \
	./ft_strncmp.c \
	./ft_strnstr.c \
	./ft_strrchr.c \
	./ft_strtrim.c \
	./ft_substr.c \
	./ft_tolower.c \
	./ft_toupper.c
OBJ = $(SRC:.c=.o)
NAME = libft.a
HEADER = libft.h
CFLAGS += -Wall -Wextra -Werror -pedantic -pedantic-errors
CC = gcc

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	@echo Creating static library
	@ar rcs $(NAME) $(OBJ)

%.o : %.c
	@echo Creating objets files $<
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY : clean fclean re tar zip

clean :
	@echo Deleting objets files
	@rm -f $(OBJ)

fclean : clean
	@echo Deleting others files
	@rm -f $(NAME) $(NAME).tar.gz $(NAME).zip

re : fclean all

tar :
	@echo Creating TAR.GZ archive
	@tar -czvf $(NAME).tar.gz $(SRC) libft.h Makefile

zip :
	@echo Creating ZIP archive
	@zip -r $(NAME).zip $(SRC) libft.h Makefile
