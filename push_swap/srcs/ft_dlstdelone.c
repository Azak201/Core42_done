
#include <push_swap.h>

void	ft_dlstdelone(t_dlist *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	if (lst)
	{
		del (lst -> content);
		free (lst);
	}
}
