NAME=checker
CC=gcc
FLAGS=-Wall -Wextra -Werror
RM=rm -rf
SRC=checker.c errors.c get_next_line.c checker_utils.c\
	get_next_line_utils.c push.c swap.c\
	rotate.c reverse_rotate.c stack_init.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)
	cp $@ ../push_swap

$(OBJ):$(SRC)
	$(CC) $(FLAGS) -c $(SRC)

clean:
	$(RM) $(OBJ)

fclean:clean
	$(RM) $(NAME)
	cd ../push_swap && rm -f $(NAME)

re:fclean all

.PHONY:all clean fclean re