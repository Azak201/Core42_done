#include "libftprintf.h"

int main()
{
    int i = ft_printf("this is test %c\nfor%s\n what else %d \n %i \n%u \n %x   %X", 'A', "Amjed", -254254822, -254254822, (unsigned int)4294967295, 2005, -25637);

    ft_printf("\n");

    int j = printf("this is test %c\nfor%s\n what else %d \n %i \n%u \n %x   %X", 'A', "Amjed", -254254822, -254254822, (unsigned int)4294967295, 2005, -25637);

    printf("\n\n\n%d      %d", i, j);
    return (0);
}
