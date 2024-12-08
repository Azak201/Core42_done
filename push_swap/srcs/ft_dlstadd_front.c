
#include <push_swap.h>

void	ft_dlstadd_front(t_dlist **lst, t_dlist *new)
{
	new -> next = *lst;
	*lst = new;
}
