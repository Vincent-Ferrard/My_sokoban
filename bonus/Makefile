##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## My_sokoban
##

SRC	=	src/all_check.c		\
		src/all_error.c		\
		src/event.c		\
		src/help.c		\
		src/level.c		\
		src/level_go.c		\
		src/main.c		\
		src/map_functions.c	\
		src/menu.c		\
		src/objective.c		\
		src/player.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_sokoban_bonus

CFLAGS	=	-W -Wall -Wextra -Iinc

LDFLAGS	=	-lncurses

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm $(NAME)

re: fclean all

.PHONY: all clean fclean re
