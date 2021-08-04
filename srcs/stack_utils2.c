#include "push_swap.h"

int has_lt(t_stack *s, int nb)
{
    t_stack *st;
    st = s;
    while (st != NULL)
    {
        if (st->nb < nb)
            return 1;
        st = st->next;
    }
    return 0;
}

int get_lte(t_stack *s, int nb)
{
    t_stack *st;
    st = s;
    while (st != NULL)
    {
        if (st->nb <= nb)
            return st->nb;
        st = st->next;
    }
    return 0;
}

int get_lt(t_stack *s, int nb)
{
    t_stack *st;
    st = s;
    while (st != NULL)
    {
        if (st->nb < nb)
            return st->nb;
        st = st->next;
    }
    return 0;
}

int has_gte(t_stack *s, int nb)
{
    t_stack *st;
    st = s;
    while (st != NULL)
    {
        if (st->nb >= nb)
            return 1;
        st = st->next;
    }
    return 0;
}

int has_gt(t_stack *s, int nb)
{
    t_stack *st;
    st = s;
    while (st != NULL)
    {
        if (st->nb > nb)
            return 1;
        st = st->next;
    }
    return 0;
}
