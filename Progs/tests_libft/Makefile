SRC = ./main.c
NAME = tests_libft.out
HEADER = greatest.h
CFLAGS += -L ../libft/ -lft
CC = gcc

all : $(NAME)

$(NAME) : $(SRC)
	@echo CREATING $(NAME)
	@$(CC) $(SRC) $(CFLAGS) -o $(NAME)

.PHONY : clean re

clean :
	@echo DELETE $(NAME)
	@rm -f $(NAME)

re : clean all
