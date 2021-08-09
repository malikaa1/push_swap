#include "push_swap.h"

int	check_argv(char *argv)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(argv);
	if (argv[i] == '-' && !ft_isdigit(argv[i + 1]))
		return (0);
	if (argv[i] == '-' && len == 1)
		return (0);
	if (argv[i] == '-' && ft_isdigit(argv[i + 1]) && len > 1)
		i++;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_sorted(t_stack *stack)
{
	int		is_sorted;
	t_stack	*s;

	s = stack;
	is_sorted = 1;
	while (s != NULL)
	{
		if (s->next != NULL && s->nb > s->next->nb)
		{
			is_sorted = 0;
			break ;
		}
		s = s->next;
	}
	return (is_sorted);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*s;

	s = *stack;
	current = NULL;
	while (s != NULL)
	{
		current = s;
		s = s->next;
		free(current);
		current = NULL;
	}
	*stack = NULL;
}
