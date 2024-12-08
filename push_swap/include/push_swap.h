#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <libft.h>

typedef struct s_dlist
{
	long			*content;
	struct s_dlist	*next;
}	t_dlist;


void				ft_dlstadd_back(t_dlist **lst, t_dlist *new);
void				ft_dlstadd_front(t_dlist **lst, t_dlist *new);
void				ft_dlstclear(t_dlist **lst, void (*del)(void *));
void				ft_dlstdelone(t_dlist *lst, void (*del)(void *));
void				ft_dlstiter(t_dlist *lst, void (*f)(long *));
t_dlist			*ft_dlstlast(t_dlist *lst);
t_dlist			*ft_dlstmap(t_dlist *lst, void *(*f)(long *), void (*del)(void *));
t_dlist			*ft_dlstnew(long *content);
int		ft_dlstsize(t_dlist *lst);


char	**spliter(int arc, char **arv);
void				handler(char **inputs);
void				ft_exit(int flag, char **str);
void				inserter(char **inputs);
void				sorter(t_dlist *stackA);


#endif