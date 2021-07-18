/*
Analysis:
--> Time Complexity O(n^2)
--> Best Case Time Complexity O(n^2)
--> Space Complexity O(1)
--> Not Stable Algorithm
--> Internal Algorithm
--> Not Adaptive because best case complexity is equal to worst case
--> Not Recursive
*/

/*
Process:
1. We will divide our array in 2 parts --> sorted & un-sorted.
2. Sorted part is of zero length & complete array is un-sorted part initially.
3. We will traverse through un-sorted part & find its minimum element let say a
4. Swap a by first element of un-sorted part.
5. Now length of sorted part increased by 1 & un-sorted part decreased by 1.
6. Do all steps until length of un-sorted part becomes 1. (Only one element left automatically sorted)
Sorted part is always a sub-array of finally sorted array.
*/

/*
Dry Run:

arr = 12 45 36 0 45 -1
No of passes = 5

1st pass: (| 12 45 36 0 45 -1)
    min = -1
    -1 | 12 45 36 0 45

2nd pass: (-1 | 12 45 36 0 45)
    min = 0
    -1 0 | 12 45 36 45

3rd pass: (-1 0 | 12 45 36 45)
    min = 12
    -1 0 12 | 45 36 45

4th pass: (-1 0 12 | 45 36 45)
    min = 36
    -1 0 12 36 | 45 45

5th pass: (-1 0 12 36 | 45 45)
    min = 45
    -1 0 12 36 45 | 45

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

void selectionSort(int *arr, int size)
{
    int pass = size - 1, min_pointer;

    for (int i = 0; i < pass; i++)
    {
        min_pointer = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_pointer])
                min_pointer = j;
        }
        if (min_pointer > i)
        {
            bswap(&arr[i], &arr[min_pointer]);
        }
    }
}

int main()
{
    int size = 6;
    int arr[] = {12, 45, 36, 0, 45, -1};

    cout << "Before Sorting :" << endl;
    show(arr, size);
    selectionSort(arr, size);
    cout << "After Sorting :" << endl;
    show(arr, size);

    return 0;
}