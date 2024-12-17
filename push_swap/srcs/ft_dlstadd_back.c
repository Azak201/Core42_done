
#include <push_swap.h>

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist *ptr;

	ptr = ft_dlstlast(*lst);
	if (!ptr)
		*lst = new;
	else
		ptr->next = new;
}
