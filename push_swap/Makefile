# COMPILER
CC = cc
# COMPILATION FLAGS
# CFLAGS = -Wall -Wextra -Werror
# LIBRARY NAME
NAME = push_swap
# SOURCE FILES
SRCS = create_stack.c instruction.c push_swap.c sort.c
# OBJECT FILES
OBJS = $(SRCS:.c=.o)

# DEFAULT TARGET
all: $(NAME)

# RULE TO COMPILE OBJECT FILES
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# RULE TO CREATE THE EXECUTABLE
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# CLEANUP RULES
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

# RECOMPILATION RULE
re: fclean all

# PHONY TARGETS
.PHONY: all clean fclean re

