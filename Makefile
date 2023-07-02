NAME	= pipex

SRC		= src

SRCS	= $(shell find $(SRC) -name '*.c')

OBJS	= $(SRCS:src/%.c=obj/%.o)

INCS	= -I./includes

FLAGS	= -Wall -Wextra -Werror# -fsanitize=address -g

HEADER	= ./includes/pipex.h

all:	mkdir $(NAME)

mkdir:
	@mkdir -p obj

obj/%.o: src/%.c $(HEADER) Makefile
	$(CC) $(FLAGS) $(INCS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(FLAGS) $(INCS) $(OBJS) -o $(NAME)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re