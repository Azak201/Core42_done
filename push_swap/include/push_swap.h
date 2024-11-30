#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>

typedef struct s_dlist
{
        s_dlist *prev;
        s_dlist *next;
        long *value;
} t_dlist;

#endif