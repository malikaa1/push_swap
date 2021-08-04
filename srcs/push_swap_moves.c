#include "push_swap.h"

void ft_pab(t_stack **stack_to, t_stack **stack_from)
{
    t_stack *current;
    t_stack *to;
    t_stack *from;

    to = *stack_to;
    from = *stack_from;
    if (!from)
        return;
    current = from;
    from = from->next;
    *stack_from = from;
    if (!to)
    {
        to = new_stack(current->nb);
        *stack_to = to;
    }
    else
    {
        current->next = to;
        *stack_to = current;
    }
}

void ft_pa(t_stack **a, t_stack **b, int print)
{
    ft_pab(a, b);
    if (print)
        printf("pa\n");
}

void ft_pb(t_stack **a, t_stack **b, int print)
{
    ft_pab(b, a);
    if (print)
        printf("pb\n");
}