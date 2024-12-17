#include <libft.h>
// #include <stdio.h>

int	ft_strcmp(const char *st1, const char *st2)
{
	int	i;

	i = 0;
	while (st1[i] && st2[i] && st1[i] == st2[i])
		i++;
	if (st1[i] == st2[i])
		return (0);
	return ((st1[i] - st2[i]));
}