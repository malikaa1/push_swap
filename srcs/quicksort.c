#include "push_swap.h"

void swap(int *a, int *b)
{
    int tmp;
    
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i;
    int j;

    i = low + 1;
    j = high;
    while (i < j)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < j)
        {
            swap(&arr[j], &arr[i]);
        }
    }
    swap(&arr[low], &arr[j]);
    return (j);
}

void quick_sort(int arr[], int low, int high)
{
    int i;
    
    if (low < high)
    {
        i = partition(arr, low, high);
        quick_sort(arr, low, i - 1);
        quick_sort(arr, i + 1, high);
    }
}