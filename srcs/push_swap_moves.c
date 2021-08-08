#include "push_swap.h"

int rotate(t_stack **stack, int nb)
{
    int length;
    int position;

    position = get_position_in_stack(*stack, nb);
    length = stack_len(*stack);
    if (position <= length / 2)
        return (1);
    else
        return (-1);
}

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
        to = current;
        to->next = NULL;
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
        ft_putstr("pa\n");
}

void ft_pb(t_stack **a, t_stack **b, int print)
{
    ft_pab(b, a);
    if (print)
        ft_putstr("pb\n");
}
