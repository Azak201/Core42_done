#include "push_swap.h"
static char **cheaker(int arc, char **arv);
int main(int arc, char **arv)
{
	char **inputs;
	inputs = cheaker(arc, arv);
}

char **chreaker(int arc, char **arv)
{
	char **tmp;
	int i;

	if (arc <= 1)
		exit(1);
	else if (arc == 2)
		tmp = ft_split();
	else
	{
		i = 1;
		tmp = (char **)malloc(sizeof(char *) * arc);
		if (!tmp)
			exit(1);
		while (i < arc)
			tmp[i - 1] = arv[i++];
		tmp[arc] = NULL;
	}
	if (!tmp)
		exit(1);
	
	return (tmp);
}