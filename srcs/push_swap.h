#ifndef PUSH_SWAP
#define PUSH_SWAP

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
typedef struct s_stack
{
  int nb;
  struct s_stack *next;
} t_stack;

t_stack *new_stack(int nb);
t_stack *push_stack(t_stack **sta, t_stack *new);
t_stack *create_stack(int argc, char **argv);
void pop_stack(t_stack **sta);
char *get_stack(t_stack *stack);
t_stack *ft_sa(t_stack **a);
t_stack *ft_sb(t_stack **b);
void ft_pa(t_stack **a, t_stack **b);
void ft_pb(t_stack **a, t_stack **b);
t_stack *ft_ra(t_stack **a);
t_stack *ft_rb(t_stack **b);
void ft_rr(t_stack **a, t_stack **b);
t_stack *ft_rra(t_stack **a);
t_stack *ft_rrb(t_stack **b);
void ft_rrr(t_stack **a, t_stack **b);

int check_argv(char *argv);
void ft_ss(t_stack **a, t_stack **b);

int stack_len(t_stack *stack);

void free_stack(t_stack *stack);
t_stack *create_stack_from(t_stack *stack);

#endif