#include "push_swap.h"

t_stack *ft_swap_ab(t_stack **stack)
{
    t_stack *next;
    t_stack *first;

    if (*stack == NULL)
        return NULL;
    first = *stack;
    next = first->next;
    first->next = next->next;
    next->next = first;
    *stack = next;
    return (*stack);
}

void ft_sa(t_stack **a, int print)
{
    ft_swap_ab(a);
    if (print)
        printf("sa\n");
}

void ft_sb(t_stack **b, int print)
{
    ft_swap_ab(b);
    if (print)
        printf("sb\n");
}

void ft_ss(t_stack **a, t_stack **b, int print)
{
    ft_swap_ab(a);
    ft_swap_ab(b);
    if (print)
        printf("ss\n");
}