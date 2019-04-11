##
## EPITECH PROJECT, 2018
## push swap
## File description:
## Makefile
##

SRC	=	src/push_swap.c	\
		src/action.c	\
		src/stock_numbers.c

OBJ	=	$(SRC:.c=.o)

LIB	=	-L./lib/my -lmy

CPPFLAGS	=	-I./include/ -Wall -Wextra

NAME	=	push_swap

all:	$(NAME)

$(NAME):	$(OBJ)
	cd lib/my && make
	gcc -o $(NAME) $(SRC) $(LIB) $(CPPFLAGS) -lncurses

clean:
	rm -f $(OBJ)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make clean

fclean: clean
	rm -f $(NAME)
	cd src/ && rm -f $(OBJ)
	cd lib/my && make fclean

re:	fclean all

.PHONY: all clean fclean re
