#include "libft.h"

int ft_is_numric(char *str)
{
	int i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);

	while (str[i] != '\0')
	{
		if ((str[i] == '+' || str[i] == '-') && i == 0)
			i++;
		if ((str[i] >= '0') && (str[i] <= '9'))
			i++;
		else
			return (1);
	}
	return (0);
}