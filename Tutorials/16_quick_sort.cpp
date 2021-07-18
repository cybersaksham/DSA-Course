/*
Analysis:
--> Avg Case Time Complexity O(nlog(n))
--> Worst Case Time Complexity O(n^2) -- When array is already sorted (because partition run through complete array)
--> Best Case Time Complexity O(nlog(n)) -- When partition returns mid index of array every time
--> Space Complexity O(nlog(n))
--> Not Stable Algorithm
--> Internal Algorithm
--> Not Adaptive
--> Recursive
*/

/*
Process:

A) Partitioning:
1. Take first index as pivot.
2. We have to partition array such that smaller elements less than pivot are at left of pivot & bigger are at right.
3. Create 2 pointers i at index 1 & j at last of array.
4. Increase i until we find an element bigger than pivot.
5. Decrease j until we find an element smaller than pivot.
6. If j > i then swap values at i & j.
7. Repeat 4 & 5 until j <= i.
8. Swap pivot with value at j.
9. Here partition is completed for index 1.
10. Now array is splitted in 2 parts. Left of pivot & right of pivot.

Do partitioning for both parts of array until array is sorted.
*/

/*
Dry Run:

arr = 12 45 36 0 45 -1

1st partition: (12 45 36 0 45 -1)
    12 -1 36 0 45 45 (-1 & 45 swapped)
    12 -1 0 36 45 45 (36 & 0 swapped)
    -1 0 12 36 45 45 (j < i)

2nd partition: (-1 0 12 36 45 45)
    left subarray: (-1 0)
        after partition process
        -1 0
    right subarray: (36 45 45)
        after partition process
        36 45 45

Finally sorted: -1 0 12 36 45 45
*/

#include <iostream>
using namespace std;

void show(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bswap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Return final index of pivot after partition process
int partition(int *arr, int low, int high)
{
    int pivot = low, i = low + 1, j = high;

    do
    {
        while (arr[i] <= arr[pivot])
            i++;
        while (arr[j] > arr[pivot])
            j--;

        if (j > i)
            bswap(&arr[i], &arr[j]);
    } while (j > i);
    bswap(&arr[j], &arr[pivot]);
    return j;
}

void quickSort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int pivot = partition(arr, low, high);
    quickSort(arr, low, pivot - 1);  // Apllying quicksort to left subarray of pivot
    quickSort(arr, pivot + 1, high); // Apllying quicksort to right subarray of pivot
}

int main()
{
    int size = 6;
    int arr[] = {12, 45, 36, 0, 45, -1};

    cout << "Before Sorting :" << endl;
    show(arr, size);
    cout << "After Sorting :" << endl;
    quickSort(arr, 0, size - 1);
    show(arr, size);

    return 0;
}