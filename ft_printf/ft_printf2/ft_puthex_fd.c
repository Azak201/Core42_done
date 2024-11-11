#include "libftprintf.h"
#include "libft/libft.h"

static void ft_printnum(char *n, int fd, int flag)
{
    int len;

    if (!n)
        return;
    len = ft_strlen(n) - 1;
    if (flag == 1)
    {
        while (len >= 0)
        {
            ft_putchar_fd(ft_tolower(n[len]), fd);
            len--;
        }
        return;
    }
    while (len >= 0)
    {
        ft_putchar_fd((n[len]), fd);
        len--;
    }
}
void ft_puthex_fd(unsigned int num, int fd, int flag)
{
    char hex[17];
    char x[9];
    int i;

    i = 0;
    ft_bzero(hex, sizeof(char) * 17);
    ft_strlcpy(hex, "0123456789ABCDEF", 17);
    if (num == 0)
    {
        write(1, x, 1);
        return;
    }
    while (num > 0)
    {
        x[i] = hex[num % 16];
        i++;
        num /= 16;
    }
    ft_printnum(x, fd, flag);
}

/*int main()
{
    ft_puthex_fd(2654, 1, 5);
}*/