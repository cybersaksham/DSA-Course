#include <iostream>
using namespace std;

int main()
{
    int A[10];

    int *ptr = &A[0];

    cout << ptr << " " << *ptr << endl; // At A[0]
    ptr++;
    cout << ptr << " " << *ptr << endl; // At A[1]

    return 0;
}