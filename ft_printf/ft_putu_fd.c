#include "libftprintf.h"
#include "libft/libft.h"

static void cond(int n, int fd);

static void ft_printnum(char *n, int fd)
{
    int len;

    len = ft_strlen(n) - 1;
    while (len >= 0)
    {
        ft_putchar_fd((n[len]), fd);
        len--;
    }
}

void ft_putu_fd(unsigned int n, int fd)
{
    char num[12];
    int i;

    i = 0;
    if (n == 0)
    {
        cond(n, fd);
        return;
    }
    while (n > 0)
    {
        num[i++] = (n % 10) + '0';
        n /= 10;
    }
    num[i] = '\0';
    ft_printnum(num, fd);
}

static void cond(int n, int fd)
{
    (void)n;
    ft_putchar_fd('0', fd);
}

/*int main()
{
    unsigned int u = -2;
    ft_putu_fd(u, 1);
}*/
