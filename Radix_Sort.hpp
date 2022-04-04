void commulativeSum(int *arr, int n) {
    if(n < 0) return;
    int *arr2 = new int[n];
    arr2[0] = 0;
    for(int i=1; i<n; i++) arr2[i] = arr[i - 1] + arr2[i - 1];
    for(int i=0; i<n; i++) arr[i] = arr2[i];
    delete[] arr2;
}

void reduceBit(int *arr, int n) {
    for(int i=0; i<n; i++) arr[i] /= 10;
}

int findMaxBit(int const *arr, int n) {
    if(n < 0) return -1;

    int maxElem = arr[0];
    for(int i=1; i<n; i++) {
        if(maxElem < arr[i]) maxElem = arr[i];
    }
    
    int count = 0;
    do {
        maxElem /= 10;
        count++;
    } while(maxElem != 0);

    return count;
}

void resetBins(int *bins) {
    for(int i=0; i<10; i++) bins[i] = 0;
}

void makeBins(int const *arr, int *bins, int n) {
    for(int i=0; i<n; i++) bins[arr[i] % 10]++;
}

void reorderElems(int *arr, int *arr2, int *bins, int n) {
    int *arr3 = new int[n];
    for(int i=0; i<n; i++) arr3[i] = arr[i];
    int *arr4 = new int[n];
    for(int i=0; i<n; i++) arr4[i] = arr2[i];

    for(int i=0; i<n; i++) {
        int a = arr4[i] % 10;
        arr[bins[a]] = arr3[i];
        arr2[bins[a]] = arr4[i];
        bins[a]++;
    }

    delete[] arr3;
    delete[] arr4;
}

void radixSort(int *arr, int n) {
    int r = findMaxBit(arr, n);

    int *bins = new int[10];
    int *arr2 = new int[n];
    for(int i=0; i<n; i++) arr2[i] = arr[i];

    for(int i=0; i<r; i++) {
        resetBins(bins); // O(10)
        makeBins(arr2, bins, n); // O(n)
        commulativeSum(bins, 10); // O(10)
        reorderElems(arr, arr2, bins, n); // O(n)
        reduceBit(arr2, n); // O(n)
    }

    delete[] bins;
    delete[] arr2;
}