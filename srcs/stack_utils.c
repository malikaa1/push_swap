#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	int		i;
	t_stack	*elemnt;

	i = 0;
	elemnt = stack;
	while (elemnt)
	{
		elemnt = elemnt->next;
		i++;
	}
	return (i);
}

t_stack	*new_empty_stack(void)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (s != NULL)
	{
		s->next = (NULL);
		return (s);
	}
	return (NULL);
}

t_stack	*new_stack(int nb)
{
	t_stack	*new_stack;

	new_stack = new_empty_stack();
	if (new_stack == NULL)
		return (NULL);
	new_stack->nb = nb;
	return (new_stack);
}

t_stack	*create_stack(int argc, char **argv)
{
	t_stack	*a_stack;
	int		i;
	int		nb;

	a_stack = NULL;
	i = argc - 1;
	while (i > 0)
	{
		 if (!check_argv(argv[i]))
		 {
		 	write(2, "Error\n", 6);
		 	return (NULL);
		}
		nb = parse_arg(argv[i]);
		 if ((nb == -1 && argv[i][0] != '-') || (nb == 0 && argv[i][0] == '-'))
		 {
		 	write(2, "Error\n", 6);
		 	return (NULL);
		 }
		a_stack = push_stack(&a_stack, new_stack(nb));
		i--;
	}
	return (a_stack);
}

t_stack	*create_stack_from(t_stack *stack)
{
	t_stack	*temp;
	int		length;
	t_stack	*new;
	int		*array;
	int		i;

	temp = stack;
	length = stack_len(stack);
	array = malloc(length * sizeof(int));
	new = NULL;
	i = 0;
	while (temp != NULL)
	{
		array[i++] = temp->nb;
		temp = temp->next;
	}
	i = 0;
	while (i < length)
	{
		push_stack(&new, new_stack(array[length - i++ - 1]));
	}
	free(array);
	return (new);
}
