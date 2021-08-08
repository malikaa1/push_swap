#include "push_swap.h"

int move_all_to_a(t_stack **a, t_stack **b)
{
    int nb_rotate;
    nb_rotate = 0;
    while (is_empty(*b) == 0)
    {
        nb_rotate += move_to_a(a, b, 1);
        debug(*a, *b);
    }

    return nb_rotate;
}

void move_all_gt_to_b(t_stack **a, t_stack **b, int median)
{
    int nb;
    while (has_gt(*a, median) == 1)
    {
        nb = get_gt(*a, median);
        move_to_top_a(a, nb, 1, 1);
        debug(*a, *b);
        ft_pb(a, b, 1);
        debug(*a, *b);
    }
}

void move_all_lte_to_b(t_stack **a, t_stack **b, int n)
{
    int nb;
    while (has_lte(*a, n) == 1)
    {
        nb = get_lte(*a, n);
        move_to_top_a(a, nb, 1, 1);
        debug(*a, *b);
        ft_pb(a, b, 1);
        debug(*a, *b);
    }
}

void move_all_to_b(t_stack **a, t_stack **b, int min, int max)
{
    int nb;
    while (get_btw(*a, min, max, &nb) == 1)
    {
        move_to_top_a(a, nb, 1, 0);
        debug(*a, *b);
        ft_pb(a, b, 1);
        debug(*a, *b);
    }
}

void move_all_top_numbers_gt_to_end_a(t_stack **a, int n)
{
    while (is_on_top(*a, get_gt(*a, n)))
    {
        ft_ra(a, 1);
    }
}
