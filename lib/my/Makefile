##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile faster
##

SRC	=	my_getnbr.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_putchar.c	\
		my_strlen.c	\
		my_strconcate.c	\
		my_strcomp.c	\
		my_str_cut.c	\
		my_revstr.c	\
		my_itoa.c	\
		my_linked_list.c\
		my_stacks.c	\
		my_manage_neighbour.c\
		my_direction.c	\
		my_engine.c	\
		my_init_s.c	\
		my_init_neighbour_s.c	\

OBJ	=	$(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME):	$(OBJ)
	@ ar rc $(NAME) $(OBJ)
	@ echo "[INFO]: lib compiled !"

%.o:	%.c
	@ echo "[INFO]: Compiling" $<
	@ gcc -o $@ -c $<

clean:
	@ rm -f $(OBJ)
	@ echo "[INFO]: files removed !"

fclean: clean
	@ rm -f $(NAME)
	@ echo "[INFO]: removed binary ->" $(NAME)

re:	fclean all
