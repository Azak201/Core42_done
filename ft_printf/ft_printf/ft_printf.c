#include "libftprintf.h"

static int pcount(const char *str);

int ft_printf(const char *format, ...)
{
    va_list list;
    int count;
    int prnum;

    if (!format)
        return (-1);
    prnum = 0;
    count = pcount(format);
    va_start(list, format);
    while (*format != '\0')
    {
        while (*format != '\0' && *format != '%')
        {
            write(1, format, 1);
            format++;
            prnum++;
        }
        if ((count > 0) && *format == '%')
        {
            prnum += definer(&format, list);
            count--;
        }
    }
    return (prnum);
}

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