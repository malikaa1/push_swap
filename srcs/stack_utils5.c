#include "push_swap.h"

void	move_max_to_end_a(t_stack **a, int max)
{
	while (get_last(*a) != max)
		ft_ra(a, 1);
}

void	do_ra(t_stack **s, int nb_rotate)
{
	while (nb_rotate-- > 0)
		ft_ra(s, 1);
}
