
#include <push_swap.h>

void ft_dlstdelone(t_dlist *lst, void (*del)(int))
{
	if (!lst)
		return;
	if (lst)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}
