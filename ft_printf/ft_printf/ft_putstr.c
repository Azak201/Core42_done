

#include "libftprintf.h"

int ft_putstr(char *s)
{
	size_t x;

	x = 0;
	while (s[x] != '\0')
	{
		ft_putchar(s[x]);
		x++;
	}
	return (x);
}
