NAME=		libnoleak.a

SRC=		noleak.c \
		init.c

OBJ=		$(SRC:.c=.o)

CC=		gcc

CFLAGS+=	-W -Wall -g -pg

$(NAME):	$(OBJ)
		ar rcs $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)