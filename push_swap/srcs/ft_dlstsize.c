
#include <push_swap.h>

int	ft_dlstsize(t_dlist *lst)
{
	int		i;
	t_dlist	*ls;

	ls = lst;
	i = 0;
	while (ls)
	{
		i ++;
		ls = ls -> next;
	}
	return (i);
}
