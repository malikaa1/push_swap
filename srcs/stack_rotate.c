#include "push_swap.h"

t_stack *ft_rotate(t_stack **stack)
{
  t_stack *elemnt;
  t_stack *temp1;
  t_stack *temp2;

  elemnt = *stack;
  if (elemnt == NULL || elemnt->next == NULL)
    return (NULL);
  temp1 = elemnt;
  elemnt = elemnt->next;
  temp2 = elemnt;
  while (temp2->next)
    temp2 = temp2->next;
  temp2->next = temp1;
  temp1->next = NULL;
  *stack = elemnt;
  return (*stack);
}

t_stack *ft_ra(t_stack **a)
{
  printf("ra\n");
  return ft_rotate(a);
}

t_stack *ft_rb(t_stack **b)
{
  printf("rb\n");
  return ft_rotate(b);
}

t_stack *ft_reverse_rotate(t_stack **stack)
{
  t_stack *elemnt;
  t_stack *temp;
  t_stack *current;

  elemnt = *stack;
  if (elemnt == NULL && elemnt->next == NULL)
    return (NULL);
  temp = *stack;
  while (temp->next)
  {
    current = temp;
    temp = temp->next;
  }
  temp->next = elemnt;
  current->next = NULL;
  *stack = temp;
  return (*stack);
}

void ft_rr(t_stack **a, t_stack **b)
{
  printf("rr\n");
  ft_rotate(a);
  ft_rotate(b);
  return;
}

t_stack *ft_rra(t_stack **a)
{
  printf("rra\n");
  ft_reverse_rotate(a);
}

t_stack *ft_rrb(t_stack **b)
{
  printf("rrb\n");
  ft_reverse_rotate(b);
}

void ft_rrr(t_stack **a, t_stack **b)
{
  ft_reverse_rotate(a);
  ft_reverse_rotate(b);
  return;
}