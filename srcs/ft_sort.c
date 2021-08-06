#include "push_swap.h"
#include "libft.h"

void r_sort_2(t_stack **a)
{
    int length;

    length = stack_len(*a);
    if ((*a)->nb > (*a)->next->nb)
        ft_sa(a, 1);
}

void r_sort_3(t_stack **a)
{
    int first;
    int second;
    int third;

    first = (*a)->nb;
    second = (*a)->next->nb;
    third = (*a)->next->next->nb;
    if (first > second && second < third && third > first)
        ft_sa(a, 1);
    if (first > second && second > third && third < first)
    {
        ft_sa(a, 1);
        ft_rra(a, 1);
    }
    if (first > second && second < third && third < first)
        ft_ra(a, 1);
    if (first < second && second > third && third > first)
    {
        ft_sa(a, 1);
        ft_ra(a, 1);
    }
    if (first < second && second > third && third < first)
        ft_rra(a, 1);
}

void sort_4(t_stack **a, t_stack **b)
{
    int max;
    max = find_biggest(*a);
    move_to_top_a(a, max, 1, 1);
    ft_pb(a, b, 1);
    r_sort_3(a);
    ft_pa(a, b, 1);
    ft_ra(a, 1);
}

void r_sort_5(t_stack **a, t_stack **b)
{
    int max;
    max = find_biggest(*a);
    move_to_top_a(a, max, 1, 1);
    ft_pb(a, b, 1);

    max = find_biggest(*a);
    move_to_top_a(a, max, 1, 1);
    ft_pb(a, b, 1);

    r_sort_3(a);
    if ((*b)->nb < (*b)->next->nb)
    {
        ft_pa(a, b, 1);
        ft_ra(a, 1);
        ft_pa(a, b, 1);
        ft_ra(a, 1);
    }
    else
    {
        ft_pa(a, b, 1);
        ft_pa(a, b, 1);
        ft_ra(a, 1);
        ft_ra(a, 1);
    }
}
