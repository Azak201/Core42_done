
#include <push_swap.h>

void ft_dlstclear(t_dlist **lst, void (*del)(int))
{
	t_dlist *tmp;
	if (!lst)
		return;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_dlstdelone(*lst, del);
		*lst = tmp;
	}
}
