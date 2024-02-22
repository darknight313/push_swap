CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

# Explicitly list source files
SRCS = create_stack.c instruction.c push_swap.c sort.c stack_checker.c utils.c
OBJS = $(SRCS:%.c=%.o)

LIBFT_DIR = libft
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

all: $(LIBFT) $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "Force cleaning"
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

