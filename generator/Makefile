##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile with make
##

SRC	=	../my_maze.c	\

NAME	=	generator

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Iinclude -g3


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
