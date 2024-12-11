#include <push_swap.h>

void swap_a(t_dlist **stackA)
{
	t_dlist *tmp;

	tmp = (*stackA)->next;
	(*stackA)->next = tmp->next;
	tmp->next = *stackA;
	*stackA = tmp;
}

void swap_b(t_dlist **stackB)
{
	t_dlist *tmp;

	tmp = (*stackB)->next;
	(*stackB)->next = tmp->next;
	tmp->next = *stackB;
	*stackB = tmp;
}
void swap_s(t_dlist **stackA, t_dlist **stackB)
{
	swap_a(&(*stackA));
	swap_b(&(*stackB));
}

void push_a(t_dlist **stackA, t_dlist **stackB)
{
	t_dlist *tmp;

	tmp = (*stackB);
	*stackB = (*stackB)->next;
	tmp->next = *stackA;
	*stackA = tmp;
}

void push_b(t_dlist **stackA, t_dlist **stackB)
{
	t_dlist *tmp;

	tmp = (*stackA);
	*stackA = (*stackA)->next;
	tmp->next = *stackB;
	*stackB = tmp;
}
