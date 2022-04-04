int partition(int *arr, int low, int high) {
    int pivot = arr[low];
    int i = low + 1, j = high;

    do {
        while(i <= high && arr[i] <= pivot) i++;
        while(j >= low && arr[j] > pivot) j--;
        if(i < j) {
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    } while(i < j);
    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quickSort(int *arr, int low, int high) {
    if(low >= high) return;
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);
    quickSort(arr, pivot + 1, high);
}