#include "push_swap.h"

void sort_medium(t_stack **a, t_stack **b)
{
    int median;
    int nb;

    median = find_median(a);
    move_all_lte_to_b(a, b, median);
    move_all_to_a(a, b);
    move_all_top_numbers_gt_to_end_a(a, median);
    move_all_gt_to_b(a, b, median);
    move_all_to_a(a, b);
    move_all_top_numbers_gt_to_end_a(a, median);
}

void sort_big(t_stack **a, t_stack **b)
{

    int length;
    int chunk;
    int d;
    int chunk_start;
    int nb_rotate;

    chunk = 0;
    length = stack_len(*a);
    chunk_start = find_smallest(*a) - 1;
    while (++chunk <= 4)
    {
        d = find_part(a, (length / 4) * chunk);
        if (chunk == 4)
        {
            d = find_part(a, ((length / 4) * chunk) - 1);
            move_all_to_b(a, b, chunk_start, find_biggest(*a) + 1);
        }
        else
            move_all_to_b(a, b, chunk_start, d + 1);
        if (chunk != 1 && chunk != 4)
            while (get_last(*a) != chunk_start)
                ft_ra(a, 1);
        nb_rotate = move_all_to_a(a, b);
        while (nb_rotate-- > 0)
            ft_ra(a, 1);
        chunk_start = d;
    }
}

void sort_small(t_stack **a, t_stack **b)
{
    int l;

    l = stack_len(*a);
    if (l == 1)
        return;
    if (l == 2)
        return (r_sort_2(a));
    if (l == 3)
        return r_sort_3(a);
    if (l == 4)
        return (sort_4(a, b));
    return (r_sort_5(a, b));
}

void sort(t_stack **a, t_stack **b)
{
    int length;

    length = stack_len(*a);
    if (is_sorted(*a))
        return;

    if (length <= 5)
        return (sort_small(a, b));
    else if (length <= 100)
        return (sort_medium(a, b));
    return (sort_big(a, b));
}