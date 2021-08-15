#include "push_swap.h"

int	has_duplicates(t_stack *a)
{
	t_stack	*stack;
	t_stack	*stack2;
	int		tmp1;
	int		tmp2;

	stack = a;
	while (stack->next != NULL)
	{
		stack2 = stack->next;
		tmp1 = stack->nb;
		while (stack2 != NULL)
		{
			tmp2 = stack2->nb;
			if (tmp1 == tmp2)
				return (1);
			stack2 = stack2->next;
		}
		stack = stack->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (argc <= 1)
		return (0);
	a = create_stack(argc, argv);
	if (a == NULL)
		return (1);
	b = NULL;
	if (has_duplicates(a) == 1 || a == NULL)
	{
		write(2, "Error\n", 6);
		free_stack(&a);
		return (1);
	}
	sort(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
