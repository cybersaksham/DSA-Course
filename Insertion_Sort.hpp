void insertionSort(int *arr, int n) {
    for(int i=1; i<n; i++) {
        for(int j=i; j>0; j--) {
            if(arr[j - 1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
            else break;
        }
    }
}