NAME=nanoshell
FLAGS=-Wall -Wextra -Werror

SRC=src/nanoshell.c

all:
	gcc $(FLAGS) -o $(NAME) $(SRC)
