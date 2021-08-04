#include "push_swap.h"

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
  static int debug = 0;

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
  int i;

  temp = stack;
  length = stack_len(stack);
  array = malloc(length * sizeof(int));
  new = NULL;
  i = 0;

  while (temp != NULL)
  {
    array[i++] = temp->nb;
    temp = temp->next;
  }
  i = 0;
  while (i < length)
  {
    push_stack(&new, new_stack(array[length - i++ - 1]));
  }

  free(array);
  return new;
}
