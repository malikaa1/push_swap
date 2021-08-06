#include "push_swap.h"

int debug_enabled = 0;

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
    if (debug_enabled == 0)
        return;
    //return;
    printf("----------\n");
    printf("A | ");
    show_stack(a);
    printf("\n");
    printf("B | ");
    show_stack(b);
    printf("\n----------\n");
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

int find_part(t_stack **stack, int index)
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
    int median = arr[index];
    free(arr);
    return median;
}
