#include "push_swap.h"

// recupere la position de 'nb' dans la stack 'stack'
int get_position_in_stack(t_stack *stack, int nb)
{
    int position;
    t_stack *s;

    s = stack;
    position = 0;
    while (s != NULL)
    {
        if (s->nb == nb)
        {
            return (position);
        }
        position++;
        s = s->next;
    }
}

/*
    retourbe 1 si nb et au sommet de la stack
*/
int is_on_top(t_stack *stack, int nb)
{
    return (stack->nb == nb);
}

/*
    retourne 1 si la stack contient un nombre inférieur or égale a nb 0 sinon.
*/
int has_lte(t_stack *s, int nb)
{
    t_stack *st;

    st = s;
    while (st != NULL)
    {
        if (st->nb <= nb)
            return (1);
        st = st->next;
    }
    return (0);
}

/*
    cherche et retoune dans 'result' un nombre entre min et max 
    min et max sont exclus
*/
int get_btw(t_stack *s, int min, int max, int *result)
{
    t_stack *st;

    st = s;
    while (st != NULL)
    {
        if (st->nb > min && st->nb < max)
        {
            *result = st->nb;
            return (1);
        }
        st = st->next;
    }
    return (0);
}
