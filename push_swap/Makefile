NAME=push_swap
CC=gcc
FLAGS=-Wall -Wextra -Werror
RM=rm -rf
SRC=push_swap.c errors.c push_commands.c swap_commands.c\
	rotate_commands.c reverse_rotate_commands.c stack_init.c\
	stack_utils.c sort_list.c small_sorts.c\
	sort_utils.c
OBJ=$(SRC:.c=.o)

all:$(NAME)

$(NAME):$(OBJ)
	$(CC) $(FLAGS) -o $@ $(OBJ)

$(OBJ):$(SRC)
	$(CC) $(FLAGS) -c $(SRC)

bonus:
	cd ../checker && make

clean:
	$(RM) $(OBJ)
	cd ../checker && make clean

fclean:
	$(RM) $(OBJ) $(NAME)
	cd ../checker && make fclean

re:fclean all

.PHONY:all clean fclean re