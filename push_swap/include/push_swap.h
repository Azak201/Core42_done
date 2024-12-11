#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <libft.h>

typedef struct s_dlist
{
	long			*content;
	struct s_dlist *next;
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
// void 				sorter2(t_dlist *stack);

void				swap_a(t_dlist **stackA);
void				swap_b(t_dlist **stackB);
void				swap_s(t_dlist **stackA, t_dlist **stackB);
void				push_a(t_dlist **stackA, t_dlist **stackB);
void				push_b(t_dlist **stackA, t_dlist **stackB);
void				rotate_a(t_dlist **stackA);
void				rotate_b(t_dlist **stackB);
void				rotate_r(t_dlist **stackA, t_dlist **stackB);
void				r_rotate_a(t_dlist **stackA);
void				r_rotate_b(t_dlist **stackB);
void				r_rotate_r(t_dlist **stackA, t_dlist **stackB);
#endif