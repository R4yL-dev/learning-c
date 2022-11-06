# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:09:36 by lray              #+#    #+#              #
#    Updated: 2022/11/06 15:02:39 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libft.a

SRCS 		:= \
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
OBJS		:= $(SRCS:.c=.o)

SRCS_BONUS	:=\
	./ft_lstadd_back_bonus.c \
	./ft_lstadd_front_bonus.c \
	./ft_lstclear_bonus.c \
	./ft_lstdelone_bonus.c \
	./ft_lstiter_bonus.c \
	./ft_lstlast_bonus.c \
	./ft_lstmap_bonus.c \
	./ft_lstnew_bonus.c \
	./ft_lstsize_bonus.c
OBJS_BONUS	:= $(SRCS_BONUS:.c=.o)

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I .

AR			:= ar
ARFLAGS		:= -r -c -s

RM			:= rm -f

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

bonus: $(OBJS) $(OBJS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS) $(OBJS_BONUS)
	$(info CREATED $@)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(info DELETED objects files)

fclean : clean
	$(RM) $(NAME) $(NAME).tar.gz $(NAME).zip
	$(info DELETED $(NAME) and archives files)

re :
	$(MAKE) fclean
	$(MAKE) all

tar :
	tar -czvf $(NAME).tar.gz $(SRCS) libft.h Makefile

zip :
	zip -r $(NAME).zip $(SRCS) libft.h Makefile

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

.PHONY : bonus clean fclean re tar zip info-
.SILENT :
