void selectionSort(int *arr, int n) {
    for(int i=0; i<n-1; i++) {
        int minInd = i, minElem = arr[i];
        for(int j=i+1; j<n; j++) {
            if(arr[j] < minElem) {
                minInd = j;
                minElem = arr[j];
            }
        }
        int tmp = arr[i];
        arr[i] = arr[minInd];
        arr[minInd] = tmp;
    }
}