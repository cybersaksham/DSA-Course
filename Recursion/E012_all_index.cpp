// Find all indoces of element in array using recursion

#include <iostream>
using namespace std;

void findElem(int a[], int size, int x)
{
    if(size == 0) return;
    findElem(a, size - 1, x);
    if(a[size - 1] == x) cout << (size - 1) << " ";
}

int main()
{
    int size;
    cin >> size;

    int *arr = new int[size];
    for(int i=0; i<size; i++) cin >> arr[i];

    int x;
    cin >> x;

    findElem(arr, size, x);
    cout << endl;

    return 0;
}