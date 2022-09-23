NAME = push_swap

SRCS =	commands.c	commands2.c	empty_b.c\
		ft_algorithm.c	ft_atoi.c	ft_check_cost.c\
		ft_find_mm.c	main.c\
		utils.c	utils2.c	ft_split.c

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

HEADER = header.h

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	cc $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	cc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME)