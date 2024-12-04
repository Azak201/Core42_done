#include "libft.h"

int ft_is_uniquenum(char **str)
{
	int i;
	int j;
	int num1;
	int num2;

	i = 0;
	while (str[i])
	{
		num1 = ft_atoi(str[i]);
		j = i + 1;
		while (str[j])
		{
			num2 = ft_atoi(str[j]);
			if (num1 == num2)
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