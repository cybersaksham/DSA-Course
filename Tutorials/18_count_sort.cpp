/*
Analysis:
--> Time Complexity O(n + m) ~ O(n) -- In all cases (where n is size of array & m is maximum element in array)
--> Space Complexity O(n)
--> Stable Algorithm
--> Internal Algorithm
--> Not Adaptive
--> Not Recursive
*/

/*
Process:

1. Find maximum element in array.
2. Make another count array size equal to maximum element + 1 & initialize all elements to 0
3. Iterate through original array & increase value of count[arr[i]] by 1
4. Iterate through count array & if count[i] > 0 then insert i in original array until count[i] becomes 0
Note: Can be done only for positive numbers
*/

/*
Dry Run:

arr = 12 45 36 0 45 5
max = 45

Making array of 45 + 1 size
count = 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 (46 size)

Iterating over original array & increasing values accordingly
count = 1 0 0 0 0 1 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1 0 0 0 0 0 0 0 0 2

Iterating over count array & changing original array
0 5 12 36 45 45

Finally sorted: 0 5 12 36 45 45
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

int max_element(int *arr, int size)
{
    int maximum = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (arr[i] > maximum)
            maximum = arr[i];
    }
    return maximum;
}

void countSort(int *arr, int size)
{
    int max = max_element(arr, size);
    int *count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }

    int j = 0;
    for (int i = 0; i < max + 1; i++)
    {
        if (count[i] > 0)
        {
            count[i]--;
            arr[j++] = i--;
        }
    }
}

int main()
{
    int size = 6;
    int arr[] = {12, 45, 36, 0, 45, 5};

    cout << "Before Sorting :" << endl;
    show(arr, size);
    cout << "After Sorting :" << endl;
    countSort(arr, size);
    show(arr, size);

    return 0;
}