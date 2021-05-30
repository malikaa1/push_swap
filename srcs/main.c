/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:21:51 by mrahmani          #+#    #+#             */
/*   Updated: 2021/05/28 22:44:11 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv) {
  t_stack *stack;

  stack = NULL;
  int i;
  int nb;
  i = 1;

  while (i < argc) {
    nb = ft_atoi(argv[i]);
    push_stack(&stack, new_stack(nb));
    i++;
  }

  show_stack(stack);
  // pop_stack(&stack);
  printf("---------------------------\n");

  // show_stack(stack);

  ft_sa(&stack);
  show_stack(stack);
}
