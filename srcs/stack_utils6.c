#include "push_swap.h"

t_stack *push_stack(t_stack **sta, t_stack *new)
{
    new->next = *sta;
    *sta = new;
    return (*sta);
}

int find_smallest(t_stack *stack)
{
    int smallest;
    t_stack *temp;

    temp = stack;
    smallest = temp->nb;
    while (temp != NULL)
    {
        if (temp->nb < smallest)
        {
            smallest = temp->nb;
        }
        temp = temp->next;
    }
    return (smallest);
}

int find_biggest(t_stack *stack)
{
    t_stack *tmp;
    int biggest;

    if (stack == NULL)
        return (0);
    biggest = stack->nb;
    tmp = stack;
    while (tmp != NULL)
    {
        if (tmp->nb > biggest)
            biggest = tmp->nb;
        tmp = tmp->next;
    }
    return (biggest);
}

int is_sorted(t_stack *stack)
{
    int is_sorted;
    t_stack *s;

    s = stack;
    is_sorted = 1;
    while (s != NULL)
    {
        if (s->next != NULL && s->nb > s->next->nb)
        {
            is_sorted = 0;
            break;
        }
        s = s->next;
    }
    return (is_sorted);
}
