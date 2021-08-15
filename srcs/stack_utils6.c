#include "push_swap.h"

t_stack	*push_stack(t_stack **sta, t_stack *new)
{
	new->next = *sta;
	*sta = new;
	return (*sta);
}

int	find_smallest(t_stack *stack)
{
	int		smallest;
	t_stack	*temp;

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
	return (smallest);
}

int	find_biggest(t_stack *stack)
{
	t_stack	*tmp;
	int		biggest;

	if (stack == NULL)
		return (0);
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

int	find_median(t_stack **stack)
{
	int		stack_length;
	int		*arr;
	int		i;
	int		median;
	t_stack	*s;

	stack_length = stack_len(*stack);
	arr = malloc((stack_length) * sizeof(int *));
	i = 0;
	s = *stack;
	while (s != NULL)
	{
		arr[i++] = s->nb;
		s = s->next;
	}
	quick_sort(arr, 0, stack_length - 1);
	median = arr[stack_length / 2];
	free(arr);
	return (median);
}

int	find_part(t_stack **stack, int index)
{
	int		stack_length;
	int		*arr;
	int		i;
	t_stack	*s;
	int		median;

	stack_length = stack_len(*stack);
	arr = malloc((stack_length) * sizeof(int *));
	i = 0;
	s = *stack;
	while (s != NULL)
	{
		arr[i++] = s->nb;
		s = s->next;
	}
	quick_sort(arr, 0, stack_length - 1);
	median = arr[index];
	free(arr);
	return (median);
}
