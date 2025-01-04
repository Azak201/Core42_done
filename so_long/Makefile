SRCS =srcs/main.c srcs/handling.c srcs/floodfill.c

OBJ =$(SRCS:srcs/%.c=obj/%.o)

NAME=so_long

CC = cc 
CFLAGS = -Wall -Wextra -Werror -I./libft/includes -I./includes
LINKER= -L./libft/ -lft -lmlx -lXext -lX11
LIB_PATH = ./libft

all: libft $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -g $(LINKER) -o $@

libft :
	make -C $(LIB_PATH)

obj/%.o : srcs/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -g -c $< -o $@

clean:
	make -C $(LIB_PATH) clean
	rm -rf obj

fclean: clean
	make -C $(LIB_PATH) fclean
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re libft
