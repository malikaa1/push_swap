/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:21:51 by mrahmani          #+#    #+#             */
/*   Updated: 2021/07/30 18:40:25 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{

  t_stack *a;
  t_stack *b;
  int length;

  if (argc <= 1)
    return 0;
  a = create_stack(argc, argv);
  b = NULL;

  sort(&a, &b);

  debug(a, b);
  return 0;
}
