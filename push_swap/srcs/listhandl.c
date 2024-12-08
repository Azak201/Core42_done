#include <push_swap.h>
#include <stdio.h>

char **spliter(int arc, char **arv)
{
	char **tmp;
	int i;

	if (arc <= 1)
		ft_exit(1, NULL);
	else if (arc == 2)
		tmp = ft_split(arv[1], ' ');
	else
	{
		i = 0;
		tmp = (char **)malloc(sizeof(char *) * arc);
		if (!tmp)
			ft_exit(1, NULL);
		while (++i < arc)
		{
			tmp[i - 1] = ft_strdup(arv[i]);
			if (!tmp[i - 1])
				ft_exit(2, tmp);
		}
		tmp[i - 1] = NULL;
	}
	if (!tmp)
		ft_exit(1, NULL);
	return (tmp);
}

void handler(char **inputs)
{
	int i;

	i = 0;
	while (inputs[i])
	{
		if ((ft_is_numric(inputs[i])))
			ft_exit(2, inputs);
		i++;
	}
	if ((ft_is_in_bound(inputs)))
		ft_exit(2, inputs);
	if ((ft_is_uniquenum(inputs)))
		ft_exit(2, inputs);
}

void ft_exit(int flag, char **str)
{
	int i;

	i = 0;
	if (flag == 1)
	{
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
	else
	{
		if (str)
		{
			while (str[i])
				free(str[i++]);
			free(str);
		}
		if (flag == 2)
			ft_putstr_fd("Error\n", 1);
		else
			ft_putstr_fd("Done\n", 1);
		exit(1);
	}
}

static void print(long *cont)
{
	printf("%ld\n", *cont);
}
void inserter(char **inputs)
{
	int i;
	long *num;
	t_dlist *stack;
	t_dlist *item;

	i = 0;
	num = (long *)malloc(sizeof(long));
	if (!num || !inputs)
		ft_exit(1, NULL);
	*num = ft_latoi(inputs[i++]);
	stack = ft_dlstnew(num);
	while (inputs[i])
	{
		num = (long *)malloc(sizeof(long));
		*num = ft_latoi(inputs[i]);
		item = ft_dlstnew(num);
		ft_dlstadd_back(&stack, item);
		i++;
	}
	ft_dlstiter(stack, print); //============>delete this line
	sorter(stack);
	ft_dlstclear(&stack, free);
}