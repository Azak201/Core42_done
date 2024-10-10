#include "libftprintf.h"

static void cond(int n);

static void ft_printnum(char *n)
{
    int len;

    len = ft_strlen(n) - 1;
    while (len >= 0)
    {
        ft_putchar((n[len]));
        len--;
    }
}

void ft_putu(unsigned int n)
{
    char num[12];
    int i;

    i = 0;
    if (n == 0)
    {
        cond(n);
        return;
    }
    while (n > 0)
    {
        num[i++] = (n % 10) + '0';
        n /= 10;
    }
    num[i] = '\0';
    ft_printnum(num);
}

static void cond(int n)
{
    (void)n;
    ft_putchar('0');
}

/*int main()
{
    unsigned int u = -2;
    ft_putu(u, 1);
}*/
