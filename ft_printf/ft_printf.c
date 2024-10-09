#include "libftprintf.h"
#include "libft/libft.h"

static void printarg2(const char **str, va_list arglist);
static int pcount(const char *str)
{
    int count = 0;
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            count++;
            if (str[i + 1] == '%')
                i++;
        }
        i++;
    }
    return (count);
}

static void printarg(const char **str, va_list arglist)
{
    char c;
    char *s;
    int i;

    if (str == NULL)
        return;
    (*str)++;
    if ((**str) == 'c')
    {
        c = va_arg(arglist, int);
        ft_putchar_fd(c, 1);
        (*str)++;
        return;
    }
    else if ((**str) == 's')
    {
        s = va_arg(arglist, char *);
        ft_putstr_fd(s, 1);
        (*str)++;
        return;
    }
    else if ((**str) == 'd' || (**str) == 'i')
    {
        i = va_arg(arglist, int);
        ft_putnbr_fd(i, 1);
        (*str)++;
        return;
    }
    else
        printarg2(str, arglist);
}
static void printarg2(const char **str, va_list arglist)
{
    unsigned int u;
    void *p;
    unsigned int hex;

    if (str == NULL)
        return;
    if ((**str) == 'p')
    {
        p = va_arg(arglist, void *);
        ft_putstr_fd(p, 1);
        (*str)++;
        return;
    }
    else if ((**str) == 'u')
    {
        u = va_arg(arglist, unsigned int);
        ft_putu_fd(u, 1);
        (*str)++;
        return;
    }
    else if ((**str) == 'x' || (**str) == 'X')
    {
        hex = va_arg(arglist, unsigned int);
        if ((**str) == 'x')
            ft_puthex_fd(hex, 1, 1);
        if ((**str) == 'X')
            ft_puthex_fd(hex, 1, 2);
        (*str)++;
        return;
    }
}

int ft_printf(const char *format, ...)
{
    va_list list;
    int count;
    int i;

    if (format == NULL)
        return (-1);
    count = pcount(format);
    va_start(list, format);
    i = 0;
    while (i < count)
    {
        while (*format != '\0' && *format != '%')
        {
            write(1, format, 1);
            format++;
        }
        printarg(&format, list);
        i++;
    }
    while (*format != '\0' && *format != '%')
    {
        write(1, format, 1);
        format++;
    }
    return (1);
}

int main()
{
    ft_printf("this is test %c\nfor%s\n what else %d \n %i \n%u \n %x   %X", 'A', "Amjed", -254254822, -254254822, (unsigned int)4294967295, 2005, -25637);
    // printf("\nthis is test %c\nfor%s\n what else %d \n %i \n%u \n %x   %X", 'A', "Amjed", -254254822, -254254822, (unsigned int)4294967295, 2005, -25637);
    return (0);
}