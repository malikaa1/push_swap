#include "push_swap.h"

int	check_argv(char *argv)
{
	int		i;
	int		len;

	i = 0;
	len = len_arg(argv);
	if (len == 0)
		return (0);
	while (argv[i] == '\f' || argv[i] == '\t' || argv[i] == '\v'
		|| argv[i] == '\r' || argv[i] == '\n' || argv[i] == ' ')
		i++;
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[i] != '\0')
	{
		if (isdigit(argv[i]) == 0)
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
