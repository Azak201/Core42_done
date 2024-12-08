SRCS= 	srcs/ft_dlstadd_back.c	 srcs/ft_dlstclear.c   srcs/ft_dlstiter.c  srcs/ft_dlstmap.c  srcs/ft_dlstsize.c  srcs/main.c  srcs/OP2.c\
	srcs/ft_dlstadd_front.c  srcs/ft_dlstdelone.c  srcs/ft_dlstlast.c  srcs/ft_dlstnew.c  srcs/listhandl.c	  srcs/OP1.c

OBJ = $(SRCS:srcs/%.c=obj/%.o)

CC = cc 
CFLAGS = -Wall -Wextra -Werror

LIB_BATH = ./libft

LIB_L = -L./libft -lft

INCLUDE = -I./include 
INC2 = -I./libft/include

NAME = push_swap

all : LIB $(NAME)

LIB:
	make -C $(LIB_BATH) 

$(NAME) : $(OBJ)
	$(CC) $^ -g $(LIB_L) -o $@

obj/%.o : srcs/%.c
	@mkdir -p obj
	$(CC) $(CFLAGS) -g $(INCLUDE) $(INC2) -c $< -o $@


clean :
	make -C $(LIB_BATH) clean
	rm -f $(OBJ)
	@rm -rf obj

fclean : clean
	make -C $(LIB_BATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re LIB

