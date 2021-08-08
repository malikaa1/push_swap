#include "push_swap.h"

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

    free_stack(&stack);
    return (moves);
}

void move_gt_to_b(t_stack **a, t_stack **b, int n, int use_reverse)
{
    int nb;

    while (has_gt(*a, n) == 1)
    {
        nb = get_gt(*a, n);
        move_to_top_a(a, nb, 1, use_reverse);
        ft_pb(a, b, 1);
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
        ft_pa(a, b, print);
        ft_ra(a, print);
        return (0);
    }
    else
    {
        move_to_top_b(b, largest, print);
        ft_pa(a, b, print);
        return (1);
    }
}
