#include "push_swap.h"

void	sort_medium(t_stack **a, t_stack **b)
{
	int	median;
	int	nb;

	median = find_median(a);
	move_all_lte_to_b(a, b, median);
	move_all_to_a(a, b);
	move_all_top_numbers_gt_to_end_a(a, median);
	move_all_gt_to_b(a, b, median);
	move_all_to_a(a, b);
	move_all_top_numbers_gt_to_end_a(a, median);
}

void	sort_big(t_stack **a, t_stack **b)
{
	int	length;
	int	chunk;
	int	d;
	int	chunk_start;
	int	nb_rotate;

	chunk = 0;
	length = stack_len(*a);
	chunk_start = find_smallest(*a) - 1;
	while (++chunk <= 4)
	{
		d = find_part(a, (length / 4) * chunk);
		if (chunk == 4)
		{
			//d = find_part(a, ((length / 4) * chunk) - 1);
			move_all_to_b(a, b, chunk_start, find_biggest(*a) + 1);
		}
		else
			move_all_to_b(a, b, chunk_start, d + 1);
		if (chunk != 1 && chunk != 4)
			move_max_to_end_a(a, chunk_start);
		nb_rotate = move_all_to_a(a, b);
		do_ra(a, nb_rotate);
		chunk_start = d;
	}
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	l;

	l = stack_len(*a);
	if (l == 1)
		return ;
	if (l == 2)
		return (r_sort_2(a));
	if (l == 3)
		return (r_sort_3(a));
	if (l == 4)
		return (sort_4(a, b));
	return (r_sort_5(a, b));
}

void	sort(t_stack **a, t_stack **b)
{
	int	length;

	length = stack_len(*a);
	if (is_sorted(*a))
		return ;
	if (length <= 5)
		return (sort_small(a, b));
	else if (length <= 100)
		return (sort_medium(a, b));
	return (sort_big(a, b));
}

int	partition(int arr[], int low, int high)
{
	int	pivot;
	int	i;
	int	j;

	pivot = arr[low];
	i = low + 1;
	j = high;
	while (i < j)
	{
		while (arr[i] <= pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i < j)
			swap(&arr[j], &arr[i]);
	}
	swap(&arr[low], &arr[j]);
	return (j);
}
