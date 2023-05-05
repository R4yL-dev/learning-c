# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 17:30:08 by lray              #+#    #+#              #
#    Updated: 2023/05/05 15:41:20 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

SRCS 		:= \
	./main.c \
	./args_parser.c \
	./map_parser.c \
	./map_checker.c \
	./map_utils.c \
	./utils.c \
	./error.c \
	./debug.c

OBJS		:= $(SRCS:.c=.o)

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= -I./ -I./libft/

LIBS		:= \
	./libft/libft.a

RM			:= rm -f
MAKEFLAGS   += --no-print-directory

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft/
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(LIBS) -o $(NAME)
	$(info CREATED $(NAME))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info CREATED $@)

clean :
	@make clean -C libft/
	$(RM) $(OBJS)
	$(info DELETED objects files)

fclean : clean
	@make fclean -C libft/
	$(RM) $(NAME)
	$(info DELETED $(NAME))

re :
	$(MAKE) fclean
	$(MAKE) all

info-%:
	$(MAKE) --dry-run --always-make $* | grep -v "info"

.PHONY : clean fclean re info-
.SILENT :
