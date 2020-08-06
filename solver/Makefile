##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile with make
##

SRC	=	../solver.c	\

NAME	=	solver

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude


all: 		$(NAME)


$(NAME):	$(OBJ)
		make -C ../lib/my
		gcc -o $(NAME) $(CFLAGS) $(OBJ) -L ../lib/my -lmy

clean:
		@ rm -f $(OBJ)
		@ rm -f *~ *#

fclean:		clean
		@ rm -f $(NAME)

re: 	fclean all

.PHONY: 	all re clean fclean
