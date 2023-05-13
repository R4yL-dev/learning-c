# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/29 17:30:08 by lray              #+#    #+#              #
#    Updated: 2023/05/13 18:59:48 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= so_long

SRCS 		:= \
	./main.c \
	./args_parser.c \
	./map_parser.c \
	./map_checker.c \
	./map_utils.c \
	./game.c \
	./game_utils.c \
	./handler.c \
	./player_move.c \
	./img.c \
	./utils.c \
	./debug.c

OBJS		:= $(SRCS:.c=.o)

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= -I./ -I./libft/
MLX			:= -Imlx ./mlx/libmlx.a -framework OpenGL -framework AppKit

LIBS		:= \
	./libft/libft.a

RM			:= rm -f
MAKEFLAGS   += --no-print-directory

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft/
	@make -C mlx
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) $(MLX) $(LIBS) -o $(NAME)
	$(info CREATED $(NAME))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(info CREATED $@)

clean :
	@make clean -C libft/
	@make clean -C mlx/
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
