#include<push_swap.h>

void r_rotate_r(t_dlist **stackA, t_dlist **stackB)
{
	r_rotate_a(&(*stackA));
	r_rotate_b(&(*stackB));
}