
#include <push_swap.h>

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*newitem;

	newitem = malloc(sizeof(t_dlist));
	if (!newitem)
		return (NULL);
	newitem->content = content;
	newitem->next = NULL;
	return (newitem);
}
