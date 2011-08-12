NAME=		test

SRC=		main.c

OBJ=		$(SRC:.c=.o)

CC=		gcc

CFLAGS+=	-W -Wall -I ./../lib -g -pg

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) -pg -L ../lib/ -lnoleak

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)