void downHeapify(int *arr, int n) {
    if(n <= 1) return;
    int parentInd = 0;
    while(parentInd < n) {
        int minInd = parentInd;
        int lci = 2 * parentInd + 1, rci = 2 * parentInd + 2;

        if(lci < n && arr[lci] > arr[minInd]) minInd = lci;
        if(rci < n && arr[rci] > arr[minInd]) minInd = rci;
        if(minInd == parentInd) break;

        int tmp = arr[minInd];
        arr[minInd] = arr[parentInd];
        arr[parentInd] = tmp;
        parentInd = minInd;
    }
}

void upHeapify(int *arr, int n) {
    if(n <= 1) return;
    int childInd = n - 1;
    while(childInd > 0) {
        int parentInd = (childInd - 1) / 2;
        if(arr[parentInd] < arr[childInd]) {
            int tmp = arr[parentInd];
            arr[parentInd] = arr[childInd];
            arr[childInd] = tmp;
            childInd = parentInd;
        }
        else break;
    }
}

void heapSort(int *arr, int n) {
    if(n <= 1) return;
    int heapEndInd = 0;

    // Creating Heap
    while(heapEndInd < n - 1) upHeapify(arr, ++heapEndInd);

    // Destroying Heap
    while(heapEndInd > 0) {
        int tmp = arr[0];
        arr[0] = arr[heapEndInd];
        arr[heapEndInd] = tmp;
        downHeapify(arr, --heapEndInd);
    }
}