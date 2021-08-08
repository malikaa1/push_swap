#include "push_swap.h"

int debug_enabled = 0;

void show_stack(t_stack *stack)
{
    t_stack *s;
 
    s = stack;
    while (s != NULL)
    {
        printf("%d ", s->nb);
        s = s->next;
    }
}

void debug(t_stack *a, t_stack *b)
{
    if (debug_enabled == 0)
        return;
    printf("----------\n");
    printf("A | ");
    show_stack(a);
    printf("\n");
    printf("B | ");
    show_stack(b);
    printf("\n----------\n");
}

