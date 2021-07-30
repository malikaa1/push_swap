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

void sort(t_stack **a, t_stack **b);

void ft_sa(t_stack **a, int print);
void ft_sb(t_stack **b, int print);
void ft_pa(t_stack **a, t_stack **b, int print);
void ft_pb(t_stack **a, t_stack **b, int print);
void ft_ra(t_stack **a, int print);
void ft_rb(t_stack **b, int print);
void ft_rr(t_stack **a, t_stack **b, int print);
void ft_rra(t_stack **a, int print);
void ft_rrb(t_stack **b, int print);
void ft_rrr(t_stack **a, t_stack **b, int print);
void ft_ss(t_stack **a, t_stack **b, int print);

t_stack *new_stack(int nb);
t_stack *push_stack(t_stack **sta, t_stack *new);
t_stack *create_stack(int argc, char **argv);
void pop_stack(t_stack **sta);
char *get_stack(t_stack *stack);
int stack_len(t_stack *stack);
void free_stack(t_stack *stack);
t_stack *create_stack_from(t_stack *stack);
int get_position_in_stack(t_stack *stack, int nb);
int is_on_top(t_stack *stack, int nb);
int has_gte(t_stack *s, int nb);
int get_gt(t_stack *s, int nb);
void debug(t_stack *a, t_stack *b);
void find_largest_and_smallest(t_stack *s, int *largest, int *smallest);
int find_median(t_stack **stack);
int find_part(t_stack **stack, int index);
int is_empty(t_stack *s);
int has_lte(t_stack *s, int nb);
int has_lt(t_stack *s, int nb);
int get_lte(t_stack *s, int nb);
int is_sorted(t_stack *stack);
int has_gt(t_stack *s, int nb);
int find_smallest(t_stack *stack);

int check_argv(char *argv);

void quick_sort(int arr[], int low, int high);

#endif