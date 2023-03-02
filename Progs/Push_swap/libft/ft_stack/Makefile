# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:09:36 by lray              #+#    #+#              #
#    Updated: 2023/03/02 11:39:02 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftstack.a

SRCS 		:= \
	./ft_stkclear.c \
	./ft_stkisempty.c \
	./ft_stknew.c \
	./ft_stkpeek.c \
	./ft_stkpop.c \
	./ft_stkpush.c \
	./ft_stksize.c


OBJS		:= $(SRCS:.c=.o)

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I .

AR			:= ar
ARFLAGS		:= -r -c -s

RM			:= rm -f
MAKEFLAGS   += --no-print-directory

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info CREATED $(NAME))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

clean :
	$(RM) $(OBJS)
	$(info DELETED objects files)

fclean : clean
	$(RM) $(NAME)
	$(info DELETED $(NAME))

re :
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

.PHONY : clean fclean re info-
.SILENT :
