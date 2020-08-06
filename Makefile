##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compile with make
##

GENERATOR	=	generator/

SOLVER		=	solver/

all:
		make -C $(GENERATOR)
		make -C $(SOLVER)
		make -C lib/my -lmy

clean:
		make -C $(GENERATOR) clean
		make -C $(SOLVER) clean

fclean:		clean
		make -C $(GENERATOR) fclean
		make -C $(SOLVER) fclean
		make -C lib/my -lmy fclean

re: fclean all

.PHONY: all re clean fclean
