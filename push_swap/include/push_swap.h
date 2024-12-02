#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <libft.h>

typedef struct s_dlist
{
        struct s_dlist *prev;
        struct s_dlist *next;
        long *value;
} t_dlist;

#endif