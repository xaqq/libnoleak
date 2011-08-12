NAME=		test

SRC=		main.c

OBJ=		$(SRC:.c=.o)

CC=		gcc

CFLAGS+=	-W -Wall -I ./../lib/

$(NAME):	$(OBJ)
		$(CC) $(OBJ) -o $(NAME) -L ../lib/ -lnoleak

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)