
#include <push_swap.h>

void ft_dlstclear(t_dlist **lst, void (*del)(void *))
{
	if (!lst || !del)
		return;
	if (*lst)
	{
		ft_dlstclear(&(*lst)->next, del);
		ft_dlstdelone(*lst, del);
		*lst = NULL;
	}
}
