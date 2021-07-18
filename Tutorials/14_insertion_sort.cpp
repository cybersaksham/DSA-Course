/*
Analysis:
--> Time Complexity O(n^2)
--> Best Case Time Complexity O(n)
--> Space Complexity O(1)
--> Stable Algorithm
--> Internal Algorithm
--> Adaptive because best case complexity is less than worst case
--> Not Recursive
*/

/*
Process:
1. We will divide our array in 2 parts --> sorted & un-sorted.
2. First element is our sorted part & after that complete array is un-sorted part.
3. Let a = first element of un-sorted part, b = last element of sorted part
4. If a is greater than b no need to go a is already at correct position.
5. If a is not greater than b then push b one index forward & now b is second last element of sorted part.
6. Do this until a find its correct position & insert a there.
7. Now length of sorted part increased by 1 & un-sorted part decreased by 1.
8. Do all steps until length of un-sorted part becomes 0.
Remember sorted part is not a sub-array of finally sorted array.
*/

/*
Dry Run:

arr = 12 45 36 0 45 -1
No of passes = 5

1st pass: (12 | 45 36 0 45 -1)
    1. (j = 0, temp = 45)
        12 45 | 36 0 45 -1

2nd pass: (12 45 | 36 0 45 -1)
    1. (j = 1, temp = 36)
        12 45 45 | 0 45 -1
    2. (j = 0, temp = 36)
        12 36 45 | 0 45 -1

3rd pass: (12 36 45 | 0 45 -1)
    1. (j = 2, temp = 0)
        12 36 45 45 | 45 -1
    2. (j = 1, temp = 0)
        12 36 36 45 | 45 -1
    3. (j = 0, temp = 0)
        12 12 36 45 | 45 -1
    4. (j = -1, temp = 0)
        0 12 36 45 | 45 -1

4th pass: (0 12 36 45 | 45 -1)
    1. (j = 3, temp = 45)
        0 12 36 45 45 | -1

5th pass: (0 12 36 45 45 | -1)
    1. (j = 4, temp = -1)
        0 12 36 45 45 45 |
    2. (j = 3, temp = -1)
        0 12 36 45 45 45 |
    3. (j = 2, temp = -1)
        0 12 36 36 45 45 |
    4. (j = 1, temp = -1)
        0 12 12 36 45 45 |
    5. (j = 0, temp = -1)
        0 0 12 36 45 45 |
    6. (j = -1, temp = -1)
        -1 0 12 36 45 45 |

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

void insertionSort(int *arr, int size)
{
    int pass = size, temp, j;

    for (int i = 1; i < pass; i++)
    {
        j = i - 1;
        temp = arr[i];
        while (arr[j] > temp && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int size = 6;
    int arr[] = {12, 45, 36, 0, 45, -1};

    cout << "Before Sorting :" << endl;
    show(arr, size);
    insertionSort(arr, size);
    cout << "After Sorting :" << endl;
    show(arr, size);

    return 0;
}