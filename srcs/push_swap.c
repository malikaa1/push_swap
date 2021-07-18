#include "push_swap.h"

t_stack *new_stack(int nb)
{
  t_stack *new_stack;

  new_stack = malloc(sizeof(t_stack));
  if (new_stack == NULL)
    return NULL;
  new_stack->nb = nb;
  new_stack->next = NULL;

  return (new_stack);
}
t_stack *create_stack(int argc, char **argv)
{
  t_stack *a_stack;
  int i;
  int nb;

  a_stack = NULL;
  i = argc - 1;

  while (i > 0)
  {
    if (!check_argv(argv[i]))
    {
      write(2, "Error\n", 6);
      return NULL;
    }
    nb = ft_atoi(argv[i]);
    a_stack = push_stack(&a_stack, new_stack(nb));
    i--;
  }
  return (a_stack);
}

t_stack *create_stack_from(t_stack *stack)
{
  t_stack *temp;
  int length;
  t_stack *new;
  int *array;

  temp = stack;
  length = stack_len(stack);
  array = malloc(length * sizeof(int));
  new = NULL;

  while (temp != NULL)
  {
    *array++ = temp->nb;
    temp = temp->next;
  }

  while (length++ > 0)
  {
    push_stack(&new, new_stack(array[length - 1]));
  }

  free(array);
  return new;
}

t_stack *push_stack(t_stack **sta, t_stack *new)
{
  t_stack *pile;

  new->next = *sta;
  *sta = new;
  return (*sta);
}

void pop_stack(t_stack **sta)
{
  t_stack *temp;

  if (*sta == NULL)
    return;
  else
  {
    temp = *sta;
    *sta = temp->next;
    free(temp);
  }
}
