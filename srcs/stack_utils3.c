#include "push_swap.h"

int	get_gte(t_stack *s, int nb)
{
	t_stack	*st;

	st = s;
	while (st != NULL)
	{
		if (st->nb >= nb)
			return (st->nb);
		st = st->next;
	}
	return (0);
}

int	get_gt(t_stack *s, int nb)
{
	t_stack	*st;

	st = s;
	while (st != NULL)
	{
		if (st->nb > nb)
			return (st->nb);
		st = st->next;
	}
	return (0);
}

int	is_empty(t_stack *s)
{
	t_stack	*st;

	st = s;
	if (st != NULL)
		return (0);
	return (1);
}

void	find_largest_and_smallest(t_stack *s, int *largest, int *smallest)
{
	*largest = find_biggest(s);
	*smallest = find_smallest(s);
}

int	get_last(t_stack *s)
{
	t_stack	*st;

	st = s;
	while (st != NULL)
	{
		if (st->next == NULL)
			return (st->nb);
		st = st->next;
	}
}
