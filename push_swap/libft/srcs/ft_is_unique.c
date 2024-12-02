#include "libft.h"

int ft_is_unique(char **str)
{
	int i;
	int j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_strcmp(str[i], str[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*int main()
{
	char *arr[6];

	arr[0] = "hello";
	arr[2] = "hella";
	arr[1] = "shit";
	arr[3] = "byr";
	arr[4] = "byr";
	arr[5] = "hhhhhh";

	int x = ft_is_unique(arr);
	ft_putchar_fd((x + '0'), 1);
}*/