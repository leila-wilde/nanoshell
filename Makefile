NAME=nanoshell
FLAGS=-Wall -Wextra -Werror
SRC=last.c

all:
	gcc $(FLAGS) -o $(NAME) $(SRC)
