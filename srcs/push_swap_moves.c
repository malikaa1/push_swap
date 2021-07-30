#include "push_swap.h"

t_stack *ft_rotate(t_stack **stack)
{
    t_stack *elemnt;
    t_stack *temp1;
    t_stack *temp2;

    elemnt = *stack;
    if (elemnt == NULL || elemnt->next == NULL)
        return (NULL);
    temp1 = elemnt;
    elemnt = elemnt->next;
    temp2 = elemnt;
    while (temp2->next)
        temp2 = temp2->next;
    temp2->next = temp1;
    temp1->next = NULL;
    *stack = elemnt;
    return (*stack);
}

void ft_ra(t_stack **a, int print)
{
    ft_rotate(a);
    if (print)
        printf("ra\n");
}

void ft_rb(t_stack **b, int print)
{
    ft_rotate(b);
    if (print)
        printf("rb\n");
}

t_stack *ft_reverse_rotate(t_stack **stack)
{
    t_stack *elemnt;
    t_stack *temp;
    t_stack *current;

    elemnt = *stack;
    if (elemnt == NULL && elemnt->next == NULL)
        return (NULL);
    temp = *stack;
    while (temp->next)
    {
        current = temp;
        temp = temp->next;
    }
    temp->next = elemnt;
    current->next = NULL;
    *stack = temp;
    return (*stack);
}

void ft_rr(t_stack **a, t_stack **b, int print)
{
    ft_rotate(a);
    ft_rotate(b);
    if (print)
        printf("rr\n");
}

void ft_rra(t_stack **a, int print)
{
    ft_reverse_rotate(a);
    if (print)
        printf("rra\n");
}

void ft_rrb(t_stack **b, int print)
{
    ft_reverse_rotate(b);
    if (print)
        printf("rrb\n");
}

void ft_rrr(t_stack **a, t_stack **b, int print)
{
    ft_reverse_rotate(a);
    ft_reverse_rotate(b);
    if (print)
        printf("rrr\n");
}

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

void ft_ss(t_stack **a, t_stack **b, int print)
{
    ft_swap_ab(a);
    ft_swap_ab(b);
    if (print)
        printf("ss\n");
}