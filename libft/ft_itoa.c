#include "libft.h"

char *ft_itoa(int n)
{
    int i;
    int sign;
    char *tmp;

    i = 0;
    sign =1;
    tmp = (char *) malloc (sizeof(char) * 12);
    if (!tmp)
        return (NULL);
    if(n == -2147483648 || n == 0)
        return ((n==0)? "0" : "-2147483648");
    if(n < 0)
    {
        sign = -1;
        n *= -1;
    }
    while (n>=0)
    {
        tmp[i++]=(n % 10) + '0';
        n /= 10;
    }
}