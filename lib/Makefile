NAME=		libnoleak.a

SRC=		noleak.c

OBJ=		$(SRC:.c=.o)

CC=		gcc

CFLAGS+=	-W -Wall

$(NAME):	$(OBJ)
		ar rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)