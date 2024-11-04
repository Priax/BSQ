##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## BSQ
##

SRC	=	src/find_biggest_square.c \
		src/bsq.c \
		src/my_file.c \
		src/my_utils.c \
		src/show_bsq.c \
		src/my_putnbr.c \
		src/generator.c \
		src/my_strcat.c \

OBJ	=	$(SRC:.c=.o)

NAME = bsq

all:	$(NAME)

$(NAME):
		gcc -g3 $(SRC) -W -Wall -Wextra -I include -o $(NAME) -g -lm

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)
re:		fclean all

.PHONY:	all fclean clean re
