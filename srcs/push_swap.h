#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
#include<limits.h>

typedef struct s_stack
{
	int					nb;
	struct s_stack		*next;
}			t_stack;

t_stack	*ft_reverse_rotate(t_stack **stack);
t_stack	*new_stack(int nb);
t_stack	*new_empty_stack(void);
t_stack	*push_stack(t_stack **sta, t_stack *new);
t_stack	*create_stack(int argc, char **argv);
t_stack	*create_stack_from(t_stack *stack);
char	*get_stack(t_stack *stack);
int		rotate(t_stack **stack, int nb);
int		partition(int arr[], int low, int high);
int		stack_len(t_stack *stack);
int		get_position_in_stack(t_stack *stack, int nb);
int		is_on_top(t_stack *stack, int nb);
int		has_gte(t_stack *s, int nb);
int		get_gt(t_stack *s, int nb);
int		find_median(t_stack **stack);
int		find_part(t_stack **stack, int index);
int		is_empty(t_stack *s);
int		has_lte(t_stack *s, int nb);
int		has_lt(t_stack *s, int nb);
int		get_lte(t_stack *s, int nb);
int		is_sorted(t_stack *stack);
int		has_gt(t_stack *s, int nb);
int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
int		get_btw(t_stack *s, int min, int max, int *result);
int		get_last(t_stack *s);
int		check_argv(char *argv);
int		move_all_to_a(t_stack **a, t_stack **b);
int		move_to_a(t_stack **a, t_stack **b, int print);
int		compute_moves_b(t_stack *s, int nb);
int		len_arg(char *str);
int		isdigit(int c);
int		parse_arg(const char *str);
void	move_max_to_end_a(t_stack **a, int max);
void	do_ra(t_stack **s, int nb_rotate);
void	swap(int *a, int *b);
void	sort(t_stack **a, t_stack **b);
void	ft_sa(t_stack **a, int print);
void	ft_sb(t_stack **b, int print);
void	ft_pa(t_stack **a, t_stack **b, int print);
void	ft_pb(t_stack **a, t_stack **b, int print);
void	ft_ra(t_stack **a, int print);
void	ft_rb(t_stack **b, int print);
void	ft_rr(t_stack **a, t_stack **b, int print);
void	ft_rra(t_stack **a, int print);
void	ft_rrb(t_stack **b, int print);
void	ft_rrr(t_stack **a, t_stack **b, int print);
void	ft_ss(t_stack **a, t_stack **b, int print);
void	pop_stack(t_stack **sta);
void	free_stack(t_stack **stack);
void	debug(t_stack *a, t_stack *b);
void	find_largest_and_smallest(t_stack *s, int *largest, int *smallest);
void	sort_medium(t_stack **a, t_stack **b);
void	quick_sort(int arr[], int low, int high);
void	sort_big(t_stack **a, t_stack **b);
void	sort(t_stack **a, t_stack **b);
void	r_sort_2(t_stack **a);
void	r_sort_3(t_stack **a);
void	r_sort_5(t_stack **a, t_stack **b);
void	sort_4(t_stack **a, t_stack **b);
void	sort_small(t_stack **a, t_stack **b);
void	move_all_top_numbers_gt_to_end_a(t_stack **a, int n);
void	move_all_to_b(t_stack **a, t_stack **b, int min, int max);
void	move_all_lte_to_b(t_stack **a, t_stack **b, int n);
void	move_all_gt_to_b(t_stack **a, t_stack **b, int median);
void	move_gt_to_b(t_stack **a, t_stack **b, int n, int use_reverse);
void	move_to_top_b(t_stack **b, int nb, int print);
void	move_to_top_a(t_stack **a, int nb, int print, int use_reverse);
void	rotate_a(t_stack **a, int nb, int print, int use_reverse);
void	rotate_b(t_stack **b, int nb, int print);
void	ft_write(char *str);

#endif
