SRCS= srcs/listhandl.c srcs/main.c srcs/OP1.c srcs/OP2.c

OBJ = $(SRCS:srcs/%.c=obj/%.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror

LIB = ./libft/libft.a 
LIB_BATH = ./libft
LIB_L = -L./libft -lft 
INCLUDE = -I./include 

NAME = push_swap

all : $(LIB) $(NAME)

$(LIB):
	make -C $(LIB_BATH) bonus

$(NAME) : $(OBJ)
	$(CC) $^ $(LIB_L) -o $@

obj/%.o : srcs/%.c
	@mkdir -p obj
	$(cc) $(CFLAGS) $(INCLUDE) -c $< -o $@


clean :
	make -C $(LIB_BATH) clean
	rm -f $(OBJ)
	@rm -rf obj

fclean : clean
	make -C $(LIB_BATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re

