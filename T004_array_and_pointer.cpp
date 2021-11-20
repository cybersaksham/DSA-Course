#include <iostream>
using namespace std;

int main()
{
    int A[] = {1,2,3,4,5,6,7,8,9};

    int *ptr = &A[0];

    cout << A << " " << ptr << endl; // A is address of A[0]

    cout << *A << endl; // Index 0
    cout << *(A + 2) << endl; // Index 2

    cout << A[2] << " " << 2[A] << " " << *(A + 2) << endl; // All are same

    // Difference in A and ptr;

    // 1. Sizeof
    cout << sizeof(A) << endl; // 9 * 4
    cout << sizeof(ptr) << endl; // 8

    // 2. & operator
    cout << &A << endl; // address of A[0]
    cout << &ptr << endl; // address of ptr

    // 3. Re-assigning
    // A = A + 3; // Make no sense
    ptr = ptr + 3;
    cout << *ptr << endl; // Index 3

    return 0;
}