void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
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