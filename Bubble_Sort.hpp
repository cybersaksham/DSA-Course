void bubbleSort(int *arr, int n) {
    for(int i=n-1; i>0; i--) {
        int adapt_checker = 0;
        for(int j=0; j<i; j++) {
            if(arr[j + 1] < arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                adapt_checker++;
            }
        }
        if(adapt_checker == 0) return;
    }
}