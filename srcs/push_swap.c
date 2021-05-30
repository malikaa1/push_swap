#include "push_swap.h"

t_stack *new_stack(int nb) {
  t_stack *new_stack;

  new_stack = malloc(sizeof(t_stack));
  if (new_stack == NULL)
    return NULL;
  new_stack->nb = nb;
  new_stack->next = NULL;

  return new_stack;
}

void push_stack(t_stack **sta, t_stack *new) {
  t_stack *pile;

  pile = *sta;
  if (*sta != NULL) {
    while (pile->next) {
      pile = pile->next;
    }
    pile->next = new;
  } else
    *sta = new;
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

void show_stack(t_stack *stack) {
  while (stack != NULL) {
    printf("%d\n", stack->nb);
    stack = stack->next;
  }
}
