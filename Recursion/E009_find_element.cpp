// Find element is present in array or not using recursion

#include <iostream>
using namespace std;

int findElem(int a[], int size, int x)
{
    if(size == 1) return a[0] == x;
    return a[0] == x || findElem(a + 1, size - 1, x);
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];
    for(int i=0; i<size; i++) cin >> arr[i];

    int x;
    cin >> x;

    cout << (findElem(arr, size, x) ? "True" : "False") << endl;

    return 0;
}