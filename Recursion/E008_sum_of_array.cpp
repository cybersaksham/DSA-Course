// Find sum of all elements in array using recursion

#include <iostream>
using namespace std;

int sum(int a[], int size)
{
    if(size == 1) return a[0];
    return a[0] + sum(a + 1, size - 1);
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];
    for(int i=0; i<size; i++) cin >> arr[i];

    cout << sum(arr, size) << endl;

    return 0;
}