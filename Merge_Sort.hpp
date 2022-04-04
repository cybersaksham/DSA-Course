void merge(int *arr, int low, int mid, int high) {
    int *ans = new int[(high - low + 1) > 0 ? (high - low + 1) : 0];
    int i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high) {
        if(arr[i] <= arr[j]) ans[k++] = arr[i++];
        else ans[k++] = arr[j++];
    }
    while(i <= mid) ans[k++] = arr[i++];
    while(j <= high) ans[k++] = arr[j++];

    for(int x=0; x<k; x++) arr[x + low] = ans[x];

    delete[] ans;
}

void mergeSort(int *arr, int low, int high) {
    if(low >= high) return;
    int mid = low + (high - low) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}