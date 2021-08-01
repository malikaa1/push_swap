#include "push_swap.h"
#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int rotate(t_stack **stack, int nb)
{
    int length;
    int position;

    position = get_position_in_stack(*stack, nb);
    length = stack_len(*stack);

    if (position <= length / 2)
        return 1;
    else
        return -1;
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

void move_to_top_a(t_stack **a, int nb, int print, int use_reverse)
{
    while (is_on_top(*a, nb) == 0)
    {
        rotate_a(a, nb, print, use_reverse);
    }
}

void move_to_top_b(t_stack **b, int nb, int print)
{
    while (is_on_top(*b, nb) == 0)
    {
        rotate_b(b, nb, print);
    }
}

int compute_moves_b(t_stack *s, int nb)
{
    int moves;
    t_stack *stack;
    stack = create_stack_from(s);
    moves = 0;
    while (is_on_top(stack, nb) == 0)
    {
        rotate_b(&stack, nb, 0);
        moves++;
    }

    free_stack(stack);
    return moves;
}

void move_gt_to_b(t_stack **a, t_stack **b, int n, int use_reverse)
{
    int nb;
    while (has_gt(*a, n) == 1)
    {
        nb = get_gt(*a, n);
        move_to_top_a(a, nb, 1, use_reverse);
        debug(*a, *b);
        ft_pb(a, b, 1);
        debug(*a, *b);
    }
}

int move_to_a(t_stack **a, t_stack **b, int print)
{
    int largest;
    int smallest;
    int nb_moves_smallest;
    int nb_moves_biggest;

    find_largest_and_smallest(*b, &largest, &smallest);
    nb_moves_biggest = compute_moves_b(*b, largest);
    nb_moves_smallest = compute_moves_b(*b, smallest);

    if (nb_moves_smallest <= nb_moves_biggest)
    {
        move_to_top_b(b, smallest, print);
        debug(*a, *b);
        ft_pa(a, b, print);
        debug(*a, *b);
        ft_ra(a, print);
        debug(*a, *b);
        return 0;
    }
    else
    {
        move_to_top_b(b, largest, print);
        debug(*a, *b);
        ft_pa(a, b, print);
        debug(*a, *b);
        return 1;
    }
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