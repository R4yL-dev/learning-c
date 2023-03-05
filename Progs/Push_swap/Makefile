# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:09:36 by lray              #+#    #+#              #
#    Updated: 2023/03/05 23:42:33 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

SRCS 		:= \
	./main.c \
	./moves.c \
	./sort.c \
	./check_args.c \
	./push_swap_utils.c \
	./debug.c

LIBS		:= \
	./libs/libftprintf.a \
	./libs/libftstack.a


OBJS		:= $(SRCS:.c=.o)

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -I .

RM			:= rm -f
MAKEFLAGS   += --no-print-directory

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(LIBS) -o $(NAME)
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
