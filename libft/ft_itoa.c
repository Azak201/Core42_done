#include "libft.h"

static char	*ft_strrev(char *str);
static char	*cond(int n);

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*tmp;

	i = 0;
	sign = 1;
	tmp = (char *) malloc (sizeof(char) * 12);
	if (!tmp)
		return (NULL);
	if (n == -2147483648 || n == 0)
		return (cond(n));
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	while (n > 0)
	{
		tmp[i++] = (n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		tmp[i] = '-';
	return (ft_strrev(tmp));
}

static char	*cond(int n)
{
	if (n == 0)
		return ("0");
	return ("-2147483648");
}

static char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = ft_strlen (str);
	while (j > i)
	{
		j--;
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		i++;
	}
	return (str);
}
/*int main()
{
    int i = 0;
    int a[5]={53727,-155,634527,0,-2147483648};
    while (i <= 4)
    {
        printf("%s \n",ft_itoa(a[i]));
        i++;
    }
    return (0);
}*/
