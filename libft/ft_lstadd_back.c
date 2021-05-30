/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 15:19:06 by mrahmani          #+#    #+#             */
/*   Updated: 2021/05/28 21:21:13 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new) {
  t_list *lst;

  if (*alst) {
    lst = *alst;
    while (lst->next)
      lst = lst->next;
    lst->next = new;
  } else
    *alst = new;
}