// Find last index of element in array using recursion

#include <iostream>
using namespace std;

int findElem(int a[], int size, int x)
{
    if(size == 0) return -1;
    int prevInd = findElem(a + 1, size - 1, x);

    if(prevInd == -1)
    {
        if(a[0] == x) return 0;
        return -1;
    }
    return 1 + prevInd;
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