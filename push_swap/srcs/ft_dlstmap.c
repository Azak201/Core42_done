

#include <push_swap.h>

static void	ft_clr(t_dlist *lst, void (*del) (void *))
{
	t_dlist	*tmp;

	while (lst)
	{
		tmp = lst -> next;
		del (lst -> content);
		free (lst);
		lst = tmp;
	}
	free(lst);
}

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(long *), void (*del)(void *))
{
	t_dlist	*newlist;
	t_dlist	*tmpnode;
	void	*var;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		var = f(lst->content);
		tmpnode = ft_dlstnew(var);
		if (!tmpnode)
		{
			if (var)
				free(var);
			ft_clr(newlist, del);
			return (NULL);
		}
		ft_dlstadd_back(&newlist, tmpnode);
		lst = lst->next;
	}
	return (newlist);
}
