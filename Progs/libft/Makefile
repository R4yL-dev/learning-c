SRC = \
	./ft_atoi.c \
	./ft_bzero.c \
	./ft_calloc.c \
	./ft_isalnum.c \
	./ft_isalpha.c \
	./ft_isascii.c \
	./ft_isdigit.c \
	./ft_isprint.c \
	./ft_memchr.c \
	./ft_memcmp.c \
	./ft_memcpy.c \
	./ft_memmove.c \
	./ft_memset.c \
	./ft_strchr.c \
	./ft_strdup.c \
	./ft_strlcat.c \
	./ft_strlcpy.c \
	./ft_strlen.c \
	./ft_strncmp.c \
	./ft_strnstr.c \
	./ft_strrchr.c \
	./ft_tolower.c \
	./ft_toupper.c
OBJ = $(SRC:.c=.o)
NAME = libft.a
CFLAGS += -Wall -Wextra -Werror
CC = gcc

%.o : %.c
	$(CC) -o $@ -c $< $(CFLAGS)

$(NAME) : $(OBJ)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME) $(NAME).tar.gz $(NAME).zip

re : fclean all

tar :
	tar -czvf $(NAME).tar.gz $(SRC) libft.h Makefile

zip :
	zip -r $(NAME).zip $(SRC) libft.h Makefile

.PHONY : all clean fclean re tar zip
