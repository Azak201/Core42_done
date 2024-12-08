
#include <push_swap.h>

void	ft_dlstiter(t_dlist *lst, void (*f)(long *))
{
	while (lst)
	{
		f(lst -> content);
		lst = lst -> next;
	}
}
