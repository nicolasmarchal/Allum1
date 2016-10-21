CC	=	gcc

NAME	=	allum1

SRC	=	srcs/main.c		\
		srcs/fill_key.c	\
		srcs/ia_hard.c	\
		srcs/ia_medium.c	\
		srcs/ia_easy.c	\
		srcs/gere_menu.c	\
		srcs/gere_option.c	\
		srcs/move_down.c	\
		srcs/move_up.c	\
		srcs/gere_score.c	\
		srcs/gere_rules.c	\
		srcs/gere_redi.c	\
		srcs/parse_score.c	\
		srcs/aff_alum.c	\
		srcs/term_mod.c	\
		srcs/exec_move_q_s.c	\
		srcs/ask_for_size.c	\
		srcs/init_game.c	\
		srcs/play_the_game.c	\
		srcs/gere_signal.c	\
		srcs/print_menu.c	\
		srcs/reset_score.c	\
		srcs/buf_init.c	\
		srcs/algo_hard.c	\
		srcs/print_score.c

OBJ	=	$(SRC:.c=.o)

RM	=	rm -f

LIBWAY	=	./my_lib

LIB	=	-L./my_lib -lmy -lncurses

CFLAGS	=	-I./my_lib/ -I./include


all:		$(NAME)

$(NAME):	$(OBJ)
		make -C $(LIBWAY)
		$(CC) -o $(NAME) $(OBJ) $(LIB)

clean:
		make clean -C $(LIBWAY)
		$(RM) $(OBJ)

fclean:		clean
		make fclean -C $(LIBWAY)
		$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
