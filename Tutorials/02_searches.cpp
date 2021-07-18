/*
Time Complexities
1. linearSearch()       Linear Search       O(n)
2. binarySearch()       Binary Search       O(nlog(n))
*/

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == element)
            return i;
    }
    return -1;
}

int binarySearch(int arr[], int size, int element)
{
    int low = 0, high = size - 1, mid;

    if (arr[low] == element)
        return low;
    else if (arr[high] == element)
        return high;

    while (high > low + 1)
    {
        mid = (low + high) / 2;

        if (arr[mid] == element)
            return mid;
        else if (arr[mid] < element)
            low = mid;
        else
            high = mid;
    }
    return -1;
}

int main()
{
    // Linear Search
    int arr[] = {1, 2, 4, 7, 5, 25, 45, 12, 0, 74, 45};
    int size = sizeof(arr) / sizeof(int);
    int element = 100;
    int ind = linearSearch(arr, size, element);
    cout << "Element " << element << " found at index no " << ind << endl;

    // Binary Search
    int arr2[] = {1, 2, 3, 4, 5, 7, 25, 45, 50, 55};
    int size2 = sizeof(arr2) / sizeof(int);
    int element2 = 35;
    int ind2 = binarySearch(arr2, size2, element2);
    cout << "Element " << element2 << " found at index no " << ind2 << endl;

    return 0;
}