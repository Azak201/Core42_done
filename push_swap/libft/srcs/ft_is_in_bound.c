#include "libft.h"
#include <limits.h>

int	ft_is_in_bound(char **inputs)
{
	int		i;
	long	num;

	i = 0;
	while (inputs[i])
	{
		if ((ft_strlen(inputs[i]) > 12))
			return (1);
		num = ft_atol(inputs[i]);
		if (num < -2147483648 || num > 2147483647)
			return (1);
		i++;
	}
	return (0);
}