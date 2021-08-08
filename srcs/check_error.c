#include "push_swap.h"

int check_argv(char *argv)
{
  int i;
  int len;

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