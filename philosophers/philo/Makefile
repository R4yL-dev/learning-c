# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lray <lray@student.42lausanne.ch >         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/04 02:50:39 by lray              #+#    #+#              #
#    Updated: 2023/06/04 19:12:15 by lray             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= philo

SRCS 		:= \
	phiengine/args_parser.c \
	phiengine/context.c \
	phiengine/philo.c \
	phiengine/philos_list.c \
	phiengine/threads.c \
	phiengine/time_utils.c \
	phiengine/timing.c \
	phiengine/utils.c \
	simulation/simulation.c \
	simulation/routine.c \
	simulation/routine_solo.c \
	simulation/rtn_utils.c \
	simulation/rtn_eat.c \
	simulation/rtn_eat_utils.c \
	simulation/rtn_sleep.c \
	simulation/rtn_think.c \
	simulation/supervisor.c \
	simulation/sv_utils.c \
	main.c

OBJS		:= $(SRCS:.c=.o)

CC 			:= gcc
CFLAGS		:= -Wall -Wextra -Werror -g
CPPFLAGS	:= -I./headers

RM			:= rm -f
MAKEFLAGS   += --no-print-directory

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(CPPFLAGS) -o $(NAME)
	$(info CREATED $(NAME))

%.o : %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
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
