NAME	:= megaphone
CC		:= c++
FLAGS	:= -Wall -Wextra -Werror -g

# Source Files

SRCS := megaphone.cpp

OBJS := $(SRCS:.cpp=.o)

# Main Target
all: $(NAME)

# Executable Creation
$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	$(CC) $(FLAGS) -o $@ $(OBJS)

# Compilation Rule
%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

# Cleaning Rules
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re