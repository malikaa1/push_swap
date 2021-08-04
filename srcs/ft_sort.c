#include "push_swap.h"
#include "libft.h"

void sort_medium(t_stack **a, t_stack **b)
{
    int median;
    int nb;

    debug(*a, *b);
    median = find_median(a);

    // push all number less than or equal to median to stack b
    move_all_lte_to_b(a, b, median);

    // push back all numbers to a depending on the number of moves.
    // and move smaller number to the end of stack and keep bigger ones on top of a
    move_all_to_a(a, b);

    // move all bigger number to the end of a
    move_all_top_numbers_gt_to_end_a(a, median);

    // push all numbers greather than median to stack b
    move_all_gt_to_b(a, b, median);

    // push back all numbers to a depending on the number of moves.
    // and move smaller number to the end of stack and keep bigger ones on top of a
    move_all_to_a(a, b);

    // move all bigger number to the end of a
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
            d = find_part(a, ((length / 4) * chunk) - 1);
        move_all_to_b(a, b, chunk_start, d + 1);
        if (chunk != 1 && chunk != 4)
            while (get_last(*a) != chunk_start)
                ft_ra(a, 1);
        nb_rotate = move_all_to_a(a, b);
        while (nb_rotate-- > 0)
            ft_ra(a, 1);
        chunk_start = d;
        debug(*a, *b);
    }
}

void sort(t_stack **a, t_stack **b)
{
    int length;
    length = stack_len(*a);
    if (is_sorted(*a))
        return;

    if (length <= 5)
        return sort_small(a, b);
    else if (length <= 100)
        return sort_medium(a, b);
    return sort_big(a, b);
}

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

void r_sort_5(t_stack **a, t_stack **b)
{
    int l;
    l = find_median(a);
    move_gt_to_b(a, b, l, 1);
    r_sort_3(a);

    ft_pa(a, b, 1);
    if ((*a)->nb < (*b)->nb)
    {
        ft_ra(a, 1);
        ft_pa(a, b, 1);
        ft_ra(a, 1);
    }
    else
    {
        ft_pa(a, b, 1);
        ft_ra(a, 1);
        ft_ra(a, 1);
    }
}

void sort_small(t_stack **a, t_stack **b)
{

    int l;
    l = stack_len(*a);

    if (l == 1)
        return;
    if (l == 2)
        return r_sort_2(a);
    if (l == 3)
        return r_sort_3(a);
    return r_sort_5(a, b);
}