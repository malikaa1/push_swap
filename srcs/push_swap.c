#include "push_swap.h"

t_stack *new_stack(int nb) {
  t_stack *new_stack;

  new_stack = malloc(sizeof(t_stack));
  if (new_stack == NULL)
    return NULL;
  new_stack->nb = nb;
  new_stack->next = NULL;

  return (new_stack);
}
t_stack *create_stack(int argc, char **argv) {
  t_stack *a_stack;
  int i;
  int nb;

  a_stack = NULL;
  i = argc - 1;

  while (i > 0) {
    if (!check_argv(argv[i])) {
      write(2, "Error\n", 6);
      return NULL;
    }
    nb = ft_atoi(argv[i]);
    a_stack = push_stack(&a_stack, new_stack(nb));
    i--;
  }
  return (a_stack);
}

t_stack *push_stack(t_stack **sta, t_stack *new) {
  t_stack *pile;

  new->next = *sta;
  *sta = new;
  return (*sta);
}

void pop_stack(t_stack **sta) {
  t_stack *temp;

  if (*sta == NULL)
    return;
  else {
    temp = *sta;
    *sta = temp->next;
    free(temp);
  }
}

char *show_stack(t_stack *stack) {
  t_stack *elmnt;
  int length = stack_len(stack);
  length = length + (length - 1);
  char *r = malloc(length * sizeof(char *));
  int i = 0;
  elmnt = stack;
  if (elmnt != NULL) {
    while (elmnt != NULL) {
      // printf("%d", elmnt->nb);
      r[i++] = elmnt->nb;
      if (elmnt->next != NULL)
        r[i++] = " ";
      elmnt = elmnt->next;
    }
  }
  return (r);
}
