SRCS = ft_printf.c  ft_putchar.c  ft_puthex.c	ft_putnbr.c  ft_putp.c	ft_putstr.c  ft_putu.c	ft_strlcpy.c  ft_strlen.c  ft_tolower.c  printargs.c

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a

CC = cc

CFLAGES = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJS)
	ar crs $@ $^

%.o : %.c
	$(CC) $(CFLAGES) -c $< -o $@

clean :
	rm -f $(OBJS)
fclean : clean
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
