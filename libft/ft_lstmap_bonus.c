/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amismail <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 16:29:17 by amismail          #+#    #+#             */
/*   Updated: 2024/09/25 18:22:03 by amismail         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_clr(t_list *lst, void (*del) (void *))
{
	t_list	*tmp;

	while (lst)
	{
		tmp = lst -> next;
		del (lst -> content);
		free (lst);
		lst = tmp;
	}
	free(lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*tmpnode;

	if (!lst || !f || !del)
		return (NULL);
	newlist = ft_lstnew(f(lst->content));
	if (!newlist)
		return (NULL);
	lst = lst->next;
	while (lst)
	{
		tmpnode = ft_lstnew(f(lst -> content));
		if (!tmpnode)
		{
			ft_clr(newlist, del);
			return (NULL);
		}
		ft_lstadd_back(&newlist, tmpnode);
		lst = lst->next;
	}
	return (newlist);
}
