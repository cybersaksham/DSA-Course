#include <iostream>
using namespace std;

// Function 1
void print(int *p)
{
    cout << *p << endl;
}

// Function 2
void incrementPtr(int *p) {p++;}

// Function 3
void increment(int *p) {(*p)++;}

int main()
{
    int i = 10;
    int *ptr = &i;
    int **ptr2 = &ptr;

    cout << &i << endl;
    cout << ptr << endl;
    cout << &ptr << endl;
    cout << ptr2 << endl;

    cout << *ptr2 << endl;
    cout << **ptr2 << endl;

    return 0;
}