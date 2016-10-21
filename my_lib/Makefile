NAME	= libmy.a

CC	= gcc

RM	= rm -f

SRC	= 	my_getnbr.c	\
		my_putchar.c	\
		my_putnbr.c	\
		my_putstr.c	\
		my_strcat.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strcmp.c	\
		get_next_line.c

OBJ	= $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
