#include "libftprintf.h"

static int printarg(const char **str, va_list arglist);
static int printarg2(const char **str, va_list arglist);
static int printarg3(const char **str, va_list arglist);

int definer(const char **str, va_list arglist)
{
    (*str)++;
    if (**str == 'c')
        return (printarg(str, arglist));
    else if (**str == 's')
        return (printarg(str, arglist));
    else if (**str == 'u')
        return (printarg2(str, arglist));
    else if (**str == 'd' || **str == 'i')
        return (printarg2(str, arglist));
    else if (**str == 'p')
        return (printarg3(str, arglist));
    else if (**str == 'X')
        return (printarg3(str, arglist));
    else if (**str == 'x')
        return (printarg3(str, arglist));
    else if (**str == '%')
        (*str)++;
    return (ft_putchar('%'));
}

static int printarg(const char **str, va_list arglist)
{
    char c;
    char *s;
    int i;

    i = 0;
    if ((**str) == 'c')
    {
        c = va_arg(arglist, int);
        i = ft_putchar(c);
        (*str)++;
        return (i);
    }
    else if ((**str) == 's')
    {
        s = va_arg(arglist, char *);
        i = ft_putstr(s);
        (*str)++;
        return (i);
    }
    return (i);
}

static int printarg2(const char **str, va_list arglist)
{
    int num;
    unsigned int un;
    int i;

    i = 0;
    if ((**str) == 'u')
    {
        num = va_arg(arglist, int);
        i = ft_putnbr(num);
        (*str)++;
        return (i);
    }
    else if ((**str) == 'd' || (**str) == 'i')
    {
        un = va_arg(arglist, unsigned int);
        i = ft_putu(un);
        (*str)++;
        return (i);
    }
    return (i);
}
static int printarg3(const char **str, va_list arglist)
{
    void *p;
    unsigned int hex;
    int i;

    i = 0;
    if ((**str) == 'p')
    {
        p = va_arg(arglist, void *);
        i = ft_putstr(p);
        (*str)++;
        return (i);
    }
    else if ((**str) == 'x' || (**str) == 'X')
    {
        hex = va_arg(arglist, unsigned int);
        if ((**str) == 'x')
            i = ft_puthex(hex, 1);
        if ((**str) == 'X')
            i = ft_puthex(hex, 2);
        (*str)++;
        return (i);
    }
    return (i);
}
