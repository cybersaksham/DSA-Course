// Find first index of element in array using recursion

#include <iostream>
using namespace std;

int findElem(int a[], int size, int x)
{
    if(size == 0) return -1;
    if(a[0] == x) return 0;
    int prevInd = findElem(a + 1, size - 1, x);
    return prevInd == -1 ? -1 : prevInd + 1;
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];
    for(int i=0; i<size; i++) cin >> arr[i];

    int x;
    cin >> x;

    cout << findElem(arr, size, x) << endl;

    return 0;
}