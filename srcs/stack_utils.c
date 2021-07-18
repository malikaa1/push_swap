#include "push_swap.h"

t_stack *ft_swap_ab(t_stack **stack)
{
  t_stack *next;
  t_stack *first;

  if (*stack == NULL)
    return NULL;
  first = *stack;
  next = first->next;
  first->next = next->next;
  next->next = first;
  *stack = next;
  return (*stack);
}

t_stack *ft_sa(t_stack **a)
{
  printf("sa\n");
  return ft_swap_ab(a);
}

t_stack *ft_sb(t_stack **b)
{
  printf("sb\n");
  return ft_swap_ab(b);
}

void ft_pab(t_stack **stack_to, t_stack **stack_from)
{
  t_stack *current;
  t_stack *to;
  t_stack *from;

  to = *stack_to;
  from = *stack_from;
  if (!from)
    return;
  current = from;
  from = from->next;
  *stack_from = from;
  if (!to)
  {
    to = new_stack(current->nb);
    *stack_to = to;
  }
  else
  {
    current->next = to;
    *stack_to = current;
  }
  return;
}

void ft_pa(t_stack **a, t_stack **b)
{
  printf("pa\n");
  ft_pab(a, b);
}

void ft_pb(t_stack **a, t_stack **b)
{
  printf("pb\n");
  ft_pab(b, a);
}

void ft_ss(t_stack **a, t_stack **b)
{
  printf("ss\n");
  ft_swap_ab(a);
  ft_swap_ab(b);
  return;
}

int stack_len(t_stack *stack)
{
  int i;

  t_stack *elemnt;

  i = 0;
  elemnt = stack;
  while (elemnt)
  {
    elemnt = elemnt->next;
    i++;
  }
  return (i);
}

void free_stack(t_stack *stack)
{
  t_stack *first;
  t_stack *current;

  while (stack != NULL)
  {
    current = stack;
    stack = stack->next;
    free(current);
  }
}
