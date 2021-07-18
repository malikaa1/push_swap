/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrahmani <mrahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 21:21:51 by mrahmani          #+#    #+#             */
/*   Updated: 2021/07/18 13:31:40 by mrahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>

// int quick_sort()

void swap(int *a, int *b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int print_array(int arr[], int length)
{
  for (int i = 0; i < length; i++)
  {
    printf("%02d ", arr[i]);
  }
  printf("\n");
}

int partition(int arr[], int low, int high)
{
  int pivot = arr[low];
  int i = low;
  int j = high + 1;

  while (i < j)
  {
    do
    {
      i++;
    } while (arr[i] <= pivot);

    do
    {
      j--;
    } while (arr[j] > pivot);

    if (i < j)
    {
      swap(&arr[j], &arr[i]);
      //print_array(arr, high);
    }
  }

  swap(&arr[low], &arr[j]);
  //print_array(arr, high);

  return j;
}

void quick_sort(int arr[], int low, int high)
{
  if (low < high)
  {
    int i = partition(arr, low, high);
    quick_sort(arr, low, i - 1);
    quick_sort(arr, i + 1, high);
  }
}

int find_smallest(t_stack *stack)
{
  int smallest;
  t_stack *temp;
  temp = stack;
  smallest = temp->nb;

  while (temp != NULL)
  {
    if (temp->nb < smallest)
    {
      smallest = temp->nb;
    }
    temp = temp->next;
  }
  return smallest;
}

int sort(t_stack **a, t_stack **b)
{

  t_stack *a_temp = *a;
  t_stack *b_temp = *b;
  int smallest = 0;
  int length = stack_len(*a);

  while (stack_len(a_temp) != 0)
  {

    // find smallest
    smallest = find_smallest(a_temp);
    // move to top
    while (a_temp->nb != smallest)
    {
      ft_ra(&a_temp);
      //debug(a_temp, b_temp);
    }
    // push to satck b
    ft_pb(&a_temp, &b_temp);
    //debug(a_temp, b_temp);
  }

  while (stack_len(b_temp) != 0)
  {
    ft_pa(&a_temp, &b_temp);
    //debug(a_temp, b_temp);
  }
  *a = a_temp;
}

// 3 7 9 0 6
//

int find_biggest(t_stack *stack)
{
  if (stack == NULL)
    return (0);
  t_stack *tmp;
  int biggest;
  biggest = stack->nb;
  tmp = stack;
  while (tmp != NULL)
  {
    if (tmp->nb > biggest)
      biggest = tmp->nb;
    tmp = tmp->next;
  }

  return (biggest);
}

// char *to_base2(int nb)
// {

//   int r;
//   int q;
//   int i;
//   char *buffer;

//   i = 0;
//   q = nb;

//   while (q > 0)
//   {
//     q = q / 2;
//     i++;
//   }
//   q = nb;
//   buffer = malloc((i + 1) * sizeof(char *));
//   buffer[i] = '\0';
//   while (q > 0)
//   {
//     r = q % 2;
//     q = q / 2;
//     buffer[--i] = r + '0';
//   }
//   return buffer;
// }

int is_sorted(t_stack *stack)
{
  int is_sorted;
  t_stack *s;
  s = stack;
  is_sorted = 1;
  while (s != NULL)
  {
    if (s->next != NULL && s->nb > s->next->nb)
    {
      is_sorted = 0;
      break;
    }
    s = s->next;
  }
  return is_sorted;
}

int is_reverse_sorted(t_stack *stack)
{
  int is_sorted;
  t_stack *s;
  s = stack;
  is_sorted = 1;
  while (s != NULL)
  {
    if (s->next != NULL && s->nb < s->next->nb)
    {
      is_sorted = 0;
      break;
    }
    s = s->next;
  }
  return is_sorted;
}

// char *left_pad(char *nb, int max)
// {
//   int len;
//   char *result;
//   int count;
//   char *nb_tmp;

//   nb_tmp = nb;
//   count = 0;
//   len = ft_strlen(nb);
//   if (len >= max)
//     return nb;

//   result = malloc((max + 1) * sizeof(char *));
//   result[max] = '\0';
//   while (count < max - len)
//   {
//     result[count++] = '0';
//   }
//   while (*nb_tmp != '\0')
//   {
//     result[count++] = *nb_tmp++;
//   }
//   free(nb);
//   return result;
// }

void show_stack(t_stack *stack)
{

  t_stack *s;
  s = stack;
  while (s != NULL)
  {
    printf("%d ", s->nb);
    s = s->next;
  }
}

void debug(t_stack *a, t_stack *b)
{
  //return;
  printf("----------\n");
  printf("A | ");
  show_stack(a);
  printf("\n");
  printf("B | ");
  show_stack(b);
  printf("\n----------\n");
}

void sort_reverse_sorted(t_stack **a)
{
  int smallest;
  smallest = find_smallest(*a);
  t_stack *tmp;
  tmp = *a;
  while (tmp->nb != smallest)
  {
    ft_ra(&tmp);
  }
  *a = tmp;
}

int get_number_of_digits(int nb)
{
  int count;
  count = 0;
  while (nb % 10 > 0)
  {
    nb = nb / 10;
    count++;
  }
  return count;
}

int get_digit_at(int nb, int unit)
{

  while (unit % 10 == 0)
  {
    unit /= 10;
    nb /= 10;
  }

  return nb % 10;
}

int ft_pow(int x, int y)
{
  if (y == 0)
    return 1;

  int result;
  result = 1;
  while (y > 0)
  {
    result = result * x;
    y--;
  }

  return result;
}

int find_smallest_by_unit(t_stack *stack, int units)
{
  int smallest_digit;
  int smallest;
  t_stack *temp;
  temp = stack;
  smallest = temp->nb;
  smallest_digit = get_digit_at(temp->nb, units);

  while (temp != NULL)
  {
    if (get_digit_at(temp->nb, units) < smallest_digit)
    {
      smallest = temp->nb;
      smallest_digit = get_digit_at(temp->nb, units);
    }
    temp = temp->next;
  }
  return smallest;
}

int find_median(t_stack **stack)
{
  int stack_length = stack_len(*stack);
  int *arr = malloc((stack_length) * sizeof(int *));
  int i = 0;
  t_stack *s = *stack;
  while (s != NULL)
  {
    arr[i++] = s->nb;
    s = s->next;
  }
  quick_sort(arr, 0, stack_length - 1);
  int index = stack_length / 2;
  int median = arr[index];
  free(arr);
  return median;
}

t_stack *stack_from(t_stack *stack, int nb)
{

  t_stack *result;
  t_stack *temp;
  int i;
  i = 0;
  result = NULL;
  temp = stack;

  while (i++ < nb)
  {
    push_stack(&stack, new_stack(temp->nb));
    temp = temp->next;
  }

  return result;
}

int get_position_in_stack(t_stack *stack, int nb)
{
  int position;
  t_stack *s;
  s = stack;
  position = 0;
  while (s != NULL)
  {
    if (s->nb == nb)
    {
      return position;
    }
    position++;
    s = s->next;
  }
}

int is_on_top(t_stack *stack, int nb)
{
  return stack->nb == nb;
}

int rotate(t_stack **stack, int nb)
{
  int length;
  int position;

  position = get_position_in_stack(*stack, nb);
  length = stack_len(*stack);

  if (position <= length / 2)
    return 1;
  else
    return -1;
}

void rotate_a(t_stack **a, int nb)
{
  if (rotate(a, nb) == 1)
    ft_ra(a);
  else
    ft_rra(a);
}

void rotate_b(t_stack **b, int nb)
{
  if (rotate(b, nb) == 1)
    ft_rb(b);
  else
    ft_rrb(b);
}

void move_to_top_a(t_stack **a, int nb)
{
  while (is_on_top(*a, nb) == 0)
  {
    rotate_a(a, nb);
  }
}

void move_to_top_b(t_stack **b, int nb)
{
  while (is_on_top(*b, nb) == 0)
  {
    rotate_b(b, nb);
  }
}

int compute_moves_b(t_stack *s, int nb)
{
  int moves;
  t_stack *stack;
  stack = create_stack_from(s);
  moves = 0;
  while (is_on_top(stack, nb) == 0)
  {
    rotate_b(&stack, nb);
    moves++;
  }

  free_stack(stack);
  return moves;
}

int has_less_than(t_stack *s, int nb)
{
  t_stack *st;
  st = s;
  while (st != NULL)
  {
    if (st->nb < nb)
      return 1;
    st = st->next;
  }
  return 0;
}

int get_less_than(t_stack *s, int nb)
{
  t_stack *st;
  st = s;
  while (st != NULL)
  {
    if (st->nb < nb)
      return st->nb;
    st = st->next;
  }
  return 0;
}

int has_greater_than(t_stack *s, int nb)
{
  t_stack *st;
  st = s;
  while (st != NULL)
  {
    if (st->nb > nb)
      return 1;
    st = st->next;
  }
  return 0;
}

int get_greater_than(t_stack *s, int nb)
{
  t_stack *st;
  st = s;
  while (st != NULL)
  {
    if (st->nb > nb)
      return st->nb;
    st = st->next;
  }
  return 0;
}

int is_empty(t_stack *s)
{
  t_stack *st;
  st = s;
  if (st != NULL)
    return 0;
  return 1;
}

void find_largest_and_smallest(t_stack *s, int *largest, int *smallest)
{
  *largest = find_biggest(s);
  *smallest = find_smallest(s);
}

void move_to_a(t_stack **a, t_stack **b)
{
  int largest;
  int smallest;
  int nb_moves_smallest;
  int nb_moves_biggest;

  find_largest_and_smallest(*b, &largest, &smallest);
  nb_moves_biggest = compute_moves_b(*b, largest);
  nb_moves_smallest = compute_moves_b(*b, smallest);

  if (nb_moves_smallest < nb_moves_biggest)
  {
    move_to_top_b(b, smallest);
    ft_pa(a, b);
    ft_ra(a);
  }
  else
  {
    move_to_top_b(b, largest);
    ft_pa(a, b);
  }
}

void r_sort3(t_stack **a, t_stack **b)
{
  int median;
  int nb;
  if (is_sorted(*a))
    return;

  median = find_median(a);
  while (has_less_than(*a, median) == 1)
  {
    nb = get_less_than(*a, median);
    move_to_top_a(a, nb);
    ft_pb(a, b);
  }

  while (is_empty(*b) == 0)
  {
    move_to_a(a, b);
  }

  // while (has_greater_than(*a, median) == 1)
  // {
  //   nb = get_greater_than(*a, median);
  //   move_to_top_a(a, nb);
  //   ft_pb(a, b);
  // }

  // while (is_empty(*b) == 0)
  // {
  //   largest = find_biggest(*b);
  //   move_to_top_b(b, largest);
  //   ft_pa(a, b);
  // }
}

int main(int argc, char **argv)
{

  t_stack *a;
  t_stack *b;

  if (argc <= 1)
    return 0;
  a = create_stack(argc, argv);
  b = NULL;

  r_sort3(&a, &b);

  debug(a, b);
}

// 13 11 1 4 15 7 3 8 9 14 2 6 12 0 5 10
