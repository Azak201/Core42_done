#include <push_swap.h>

void rotate_a(t_dlist **stackA)
{
	t_dlist *tmp;

	tmp = ft_dlstlast(*stackA);
	tmp->next = (*stackA);
	(*stackA) = (*stackA)->next;
	tmp = tmp->next;
	tmp->next = NULL;
}

void rotate_b(t_dlist **stackB)
{
	t_dlist *tmp;

	tmp = ft_dlstlast(*stackB);
	tmp->next = (*stackB);
	(*stackB) = (*stackB)->next;
	tmp = tmp->next;
	tmp->next = NULL;
}
void rotate_r(t_dlist **stackA, t_dlist **stackB)
{
	rotate_a(&(*stackA));
	rotate_b(&(*stackB));
}
void r_rotate_a(t_dlist **stackA)
{
	t_dlist *tmp1;
	t_dlist *tmp2;

	tmp1 = *stackA;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		if (tmp2->next == NULL)
			break;
		tmp1 = tmp1->next;
	}
	tmp2->next = (*stackA);
	tmp1->next = NULL;
	(*stackA) = tmp2;
}
void r_rotate_b(t_dlist **stackB)
{
	t_dlist *tmp1;
	t_dlist *tmp2;

	tmp1 = *stackB;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		if (tmp2->next == NULL)
			break;
		tmp1 = tmp1->next;
	}
	tmp2->next = (*stackB);
	tmp1->next = NULL;
	(*stackB) = tmp2;
}
