#include <push_swap.h>
#include <stdio.h>

static char **spliter(int arc, char **arv);
static void handler(char **inputs);
static void ft_exit();
static void inserter(char **inputs);

int main(int arc, char **arv)
{
	char **inputs;
	int i;
	inputs = spliter(arc, arv);
	if (!inputs)
		ft_exit(1, NULL);

	i = 0;
	while (inputs[i])
		printf("%s \n", inputs[i++]);
	handler(inputs);
	// inserter(inputs);
	ft_exit(2, inputs);
}

// --------------------------------------------------------------------------------

static char **spliter(int arc, char **arv)
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
		tmp[arc] = NULL;
	}
	if (!tmp)
		ft_exit(1, NULL);
	return (tmp);
}

//---------------------------------------------------------------------------------

static void handler(char **inputs)
{
	int i;
	int c;

	i = 0;
	c = ft_is_unique(inputs);
	if (c != 0)
		ft_exit(2, inputs);
	while (inputs[i])
	{
		c = ft_is_numric(inputs[i]);
		if (c != 0)
			ft_exit(2, inputs);
		i++;
	}
	c = ft_is_in_bound(inputs);
	if (c != 0)
		ft_exit(2, inputs);
}

//-----------------------------------------------------------------------------

/*static void inserter(char **inputs)
{

}*/

//-----------------------------------------------------------------------------
static void ft_exit(int flag, char **str)
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
		while (str[i])
			free(str[i++]);
		free(str);
		ft_putstr_fd("Error\n", 1);
		exit(1);
	}
}