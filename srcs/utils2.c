#include "push_swap.h"

void s_pile(t_stack **s, int lenght) {
  t_stack *elm;

  elm = *s;
  if (lenght == 2 && elm->nb > elm->next->nb)
    ft_swap_ab(&elm);
}