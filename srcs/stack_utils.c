#include "push_swap.h"

int debug_enabled = 1;

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

int find_smallest(t_stack *stack)
{
  int smallest;
  t_stack *temp;
  temp = stack;
  smallest = temp->nb;

  while (temp != NULL)
  {
    if (temp->nb < smallest)
    {
      smallest = temp->nb;
    }
    temp = temp->next;
  }
  return smallest;
}

int find_biggest(t_stack *stack)
{
  if (stack == NULL)
    return (0);
  t_stack *tmp;
  int biggest;
  biggest = stack->nb;
  tmp = stack;
  while (tmp != NULL)
  {
    if (tmp->nb > biggest)
      biggest = tmp->nb;
    tmp = tmp->next;
  }

  return (biggest);
}

int is_sorted(t_stack *stack)
{
  int is_sorted;
  t_stack *s;
  s = stack;
  is_sorted = 1;
  while (s != NULL)
  {
    if (s->next != NULL && s->nb > s->next->nb)
    {
      is_sorted = 0;
      break;
    }
    s = s->next;
  }
  return is_sorted;
}

int is_reverse_sorted(t_stack *stack)
{
  int is_sorted;
  t_stack *s;
  s = stack;
  is_sorted = 1;
  while (s != NULL)
  {
    if (s->next != NULL && s->nb < s->next->nb)
    {
      is_sorted = 0;
      break;
    }
    s = s->next;
  }
  return is_sorted;
}

void show_stack(t_stack *stack)
{

  t_stack *s;
  s = stack;
  while (s != NULL)
  {
    printf("%d ", s->nb);
    s = s->next;
  }
}

void debug(t_stack *a, t_stack *b)
{
  if (debug_enabled == 0)
    return;
  //return;
  printf("----------\n");
  printf("A | ");
  show_stack(a);
  printf("\n");
  printf("B | ");
  show_stack(b);
  printf("\n----------\n");
}

int find_median(t_stack **stack)
{
  int stack_length = stack_len(*stack);
  int *arr = malloc((stack_length) * sizeof(int *));
  int i = 0;
  t_stack *s = *stack;
  while (s != NULL)
  {
    arr[i++] = s->nb;
    s = s->next;
  }
  quick_sort(arr, 0, stack_length - 1);
  int index = stack_length / 2;
  int median = arr[index];
  free(arr);
  return median;
}

int find_part(t_stack **stack, int index)
{
  int stack_length = stack_len(*stack);
  int *arr = malloc((stack_length) * sizeof(int *));
  int i = 0;
  t_stack *s = *stack;
  while (s != NULL)
  {
    arr[i++] = s->nb;
    s = s->next;
  }
  quick_sort(arr, 0, stack_length - 1);
  int median = arr[index];
  free(arr);
  return median;
}

t_stack *stack_from(t_stack *stack, int nb)
{

  t_stack *result;
  t_stack *temp;
  int i;
  i = 0;
  result = NULL;
  temp = stack;

  while (i++ < nb)
  {
    push_stack(&stack, new_stack(temp->nb));
    temp = temp->next;
  }

  return result;
}

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
      return position;
    }
    position++;
    s = s->next;
  }
}

int is_on_top(t_stack *stack, int nb)
{
  return stack->nb == nb;
}

int has_lte(t_stack *s, int nb)
{
  t_stack *st;
  st = s;
  while (st != NULL)
  {
    if (st->nb <= nb)
      return 1;
    st = st->next;
  }
  return 0;
}

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

int get_gte(t_stack *s, int nb)
{
  t_stack *st;
  st = s;
  while (st != NULL)
  {
    if (st->nb >= nb)
      return st->nb;
    st = st->next;
  }
  return 0;
}

int get_gt(t_stack *s, int nb)
{
  t_stack *st;
  st = s;
  while (st != NULL)
  {
    if (st->nb > nb)
      return st->nb;
    st = st->next;
  }
  return 0;
}

int is_empty(t_stack *s)
{
  t_stack *st;
  st = s;
  if (st != NULL)
    return 0;
  return 1;
}

void find_largest_and_smallest(t_stack *s, int *largest, int *smallest)
{
  *largest = find_biggest(s);
  *smallest = find_smallest(s);
}
