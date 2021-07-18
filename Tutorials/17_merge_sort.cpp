/*
Analysis:
--> Time Complexity O(nlog(n)) -- In all cases
--> Space Complexity O(n)
--> Stable Algorithm
--> Internal Algorithm
--> Not Adaptive
--> Recursive
*/

/*
Process:

A) Splitting:
1. We will split our array in 2 halves.
2. Now split 2 halves into another 4 halves.
3. Do this until we have 1-1 element left in all parts.
4. Now apply merging procedure

B) Merging:
1. We will take 2 continuous parts as argument.
2. We will traverse through them & in which part we find smaller element, we will append that element to new array.
3. Do this until one part is completed.
4. Now push all elements of another part just behind new array.
5. Insert new array in original array inplace of our both parts.
6. Now 2 sorted parts are merged into one sorted parts.

Do this until all parts get merged into one single array.
*/

/*
Dry Run:

arr = 12 45 36 0 45 -1

Splitting:
    1. 12 45 36 | 0 45 -1
    2. 12 45 | 36 | 0 45 | -1
    3. 12 | 45 | 36 | 0 | 45 | -1
    Now we will apply merging in all parts.

Merging:
    1. 12 45 | 36 | 0 45 | -1
    2. 12 36 45 | -1 0 45
    3. -1 0 12 36 45 45

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

// Merge two sorted parts of an array after sorting
void merge(int *arr, int low, int mid, int high)
{
    int i = low, j = mid + 1, k = 0, m = mid + 1, n = high + 1;
    int *fin_arr = new int[high - low + 1];

    while (i < m && j < n)
    {
        if (arr[i] <= arr[j])
            fin_arr[k] = arr[i++];
        else
            fin_arr[k] = arr[j++];
        k++;
    }

    while (j < n)
        fin_arr[k++] = arr[j++];
    while (i < m)
        fin_arr[k++] = arr[i++];

    for (int p = low; p < high + 1; p++)
    {
        arr[p] = fin_arr[p - low];
    }
    delete fin_arr;
}

void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int main()
{
    int size = 6;
    int arr[] = {12, 45, 36, 0, 45, -1};

    cout << "Before Sorting :" << endl;
    show(arr, size);
    cout << "After Sorting :" << endl;
    mergeSort(arr, 0, size - 1);
    show(arr, size);

    return 0;
}