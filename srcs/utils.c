#include "push_swap.h"

int	len_arg(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_write(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

int	parse_arg(const char *str)
{
	unsigned int		result;
	int					sign;
	
	sign = 1;
	result = 0;
	
	while (*str == '\f' || *str == '\t' || *str == '\v'
			|| *str == '\r' || *str == '\n' || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (isdigit(*str))
	{
		result = 10 * result + (*str - 48);
		str++;
		if (result > INT_MAX)
			break ;
	}
	if ((result == (unsigned int)INT_MAX + 1 && sign == -1)
			|| result <= INT_MAX)
		return (sign * result);
	if (sign == 1)
		return (-1);
	else
		return (0);
}

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
