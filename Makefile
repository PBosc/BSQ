SRCDIR	= srcs/
SRC		= $(SRCDIR)tests.c ${SRCDIR}find_BSQ.c $(SRCDIR)ft_split.c $(SRCDIR)input.c
OBJ		= $(SRC:.c=.o)
NAME	= bsq
CC		= gcc
RM		= rm -rf
CFLAGS	= 
HEADERS	= includes/

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I $(HEADERS)

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:            fclean all
