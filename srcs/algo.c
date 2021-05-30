#include "push_swap.h"

void ft_sa(t_stack **stack) {
  t_stack *next;
  t_stack *first;

  if (*stack == NULL)
    return;

  first = *stack;
  next = first->next;
  first->next = next->next;
  next->next = first;
  *stack = next;

  //   current->next = next->next;
  //   current->next->next = next;
  // current_stack->next = old_next->next;
  // old_next->next = current_stack;
}