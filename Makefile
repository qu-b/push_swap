NAME	= push_swap
RM		= rm rf

SRC		= utils.c \
			push_swap.c \
			list_utils.c \
			list_utils_2.c \
			ft_split.c \
			operations.c \
			solve.c \
			solve_2.c \
			radix.c \
			ft_quicksort.c \
			process_input.c

OBJ		= $(SRC:.c=.o)

all:
		gcc -Wall -Werror -Wextra -fsanitize=address ${SRC} -o ${NAME}

clean:
		${RM} ${OBJ}

fclean:	clean
		${RM} ${NAME}

re: fclean all
