
#include "push_swap.h"
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

void rotate_a(t_stack **a, int nb, int print, int use_reverse)
{
    if (use_reverse == 0)
    {
        ft_ra(a, print);
        return;
    }
    if (rotate(a, nb) == 1)
        ft_ra(a, print);
    else
        ft_rra(a, print);
}

void rotate_b(t_stack **b, int nb, int print)
{
    if (rotate(b, nb) == 1)
        ft_rb(b, print);
    else
        ft_rrb(b, print);
}