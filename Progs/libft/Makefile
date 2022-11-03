# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:09:36 by lray              #+#    #+#              #
#    Updated: 2022/11/03 19:48:23 by lray             ###   ########.fr        #
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
	./ft_putendl_fd.c \
	./ft_putnbr_fd.c \
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
SRC_BONUS =\
	./ft_lstadd_back_bonus.c \
	./ft_lstadd_front_bonus.c \
	./ft_lstdelone_bonus.c \
	./ft_lstlast_bonus.c \
	./ft_lstnew_bonus.c \
	./ft_lstsize_bonus.c
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)
NAME = libft.a
CFLAGS += -Wall -Wextra -Werror -pedantic -pedantic-errors
CC = gcc
AR = ar rcs $(NAME)

%.o : %.c
	@echo Creating objets files $<
	@$(CC) -I. $(CFLAGS) -o $@ -c $?

all : $(NAME)

$(NAME) : $(OBJ)
	@echo Creating $(NAME)
	@$(AR) $(OBJ)

bonus: $(OBJ) $(OBJ_BONUS)
	@echo Creating $(NAME)
	@$(AR) $(OBJ) $(OBJ_BONUS)

.PHONY : clean fclean re tar zip

clean :
	@echo Deleting objets files
	@rm -f $(OBJ) $(OBJ_BONUS)

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
