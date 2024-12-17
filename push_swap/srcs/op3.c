
#include<push_swap.h>

void r_rotate_r(t_dlist **stack_a, t_dlist **stack_b)
{
	r_rotate_a(&(*stack_a));
	r_rotate_b(&(*stack_b));
}