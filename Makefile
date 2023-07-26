CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
NAME = push_swap

SRC = big_stack_utils.c\
	check_arguments.c\
	create_stack_a.c\
	fill_struct.c\
	get_med.c\
	main.c\
	print_operation.c\
	sort_big_stack.c\
	sort_small_stack.c\
	sort_utils.c\
	stack_operations.c


OBJ = $(SRC:.c=.o)

BONUS = checker 

SRC_BONUS = bonus/check_arguments_bonus.c\
			bonus/create_stack_a_bonus.c\
			bonus/main_bonus.c\
			bonus/print_operation_bonus.c\
			bonus/stack_operations_bonus.c\
			bonus/utils_bonus.c\
			bonus/valid_move_bonus.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) push_swap.h
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ) ./libft/libft.a -o $@

bonus: $(BONUS) 

$(BONUS): $(OBJ_BONUS) bonus/push_swap_bonus.h
	make -C ./libft
	$(CC) $(CFLAGS) $(OBJ_BONUS) ./libft/libft.a -o $(BONUS)

clean:
	$(RM) $(OBJ)
	$(RM) $(OBJ_BONUS)
	make clean -C ./libft

fclean: clean
	$(RM) $(NAME) checker
	make fclean -C ./libft

re: fclean all

.PHONY : all bonus clean flclean re