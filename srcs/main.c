/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:21:51 by mrahmani          #+#    #+#             */
/*   Updated: 2021/06/20 19:46:13 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

// int quick_sort()

void debug(char *op, t_stack *a, t_stack *b) {
  int a_length = stack_len(a);
  int b_length printf("%s (%) | ()")
}

int find_smallest(t_stack *stack) {
  int smallest;
  t_stack *temp;
  temp = stack;
  smallest = temp->nb;

  while (temp != NULL) {
    if (temp->nb < smallest) {
      smallest = temp->nb;
    }
    temp = temp->next;
  }
  return smallest;
}

int sort(t_stack **a, t_stack **b) {

  t_stack *a_temp = *a;
  t_stack *b_temp = *b;
  int smallest = 0;

  while (stack_len(a_temp) != 0) {

    // find smallest
    smallest = find_smallest(a_temp);
    // move to top
    while (a_temp->nb != smallest) {
      ft_rotate(&a_temp);
      debug("ra", a_temp, b_temp);
    }
    // push to satck b
    ft_pb(&a_temp, &b_temp);
    debug("pb", a_temp, b_temp);
  }

  while (stack_len(b_temp) != 0) {
    ft_pa(&a_temp, &b_temp);
    debug("pa", a_temp, b_temp);
  }
  *a = a_temp;
}

// 3 7 9 0 6
//

int main(int argc, char **argv) {
  t_stack *a;
  t_stack *b;

  if (argc <= 1)
    return 0;
  a = create_stack(argc, argv);
  b = NULL;
  // show_stack(a);
  sort(&a, &b);
  show_stack(a);
}
