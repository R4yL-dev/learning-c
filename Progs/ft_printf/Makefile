# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/07 18:09:36 by lray              #+#    #+#              #
#    Updated: 2023/02/18 17:50:44 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= libftprintf.a

SRCS 		:= \
	./libftprintf.c \
	./libftprintf_utils.c

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
