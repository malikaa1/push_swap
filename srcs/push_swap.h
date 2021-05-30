#ifndef PUSH_SWAP
#define PUSH_SWAP

#include<stdlib.h>
#include<stdio.h>
typedef struct s_stack
{
    int nb;
    struct s_stack* next;
} t_stack;

t_stack *new_stack(int nb);
void push_stack(t_stack **sta, t_stack *new);
void pop_stack(t_stack **sta);
void show_stack(t_stack *stack);
void ft_sa(t_stack **stack);

#endif