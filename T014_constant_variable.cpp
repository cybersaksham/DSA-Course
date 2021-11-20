#include <iostream>
using namespace std;

int main()
{
    const int i = 10;
    int const j = 20;
    // i++; // Cannot change a constant variable
    // j++; // Cannot change a constant variable

    // const int k; // Must be initialized

    int a = 10;
    const int& b = a;
    a++; // Valid
    // b++; // Invalid
    cout << a << " " << b << endl;

    // Pointer to constant int
    const int *p;
    p = &a; // Can be changed
    // (*p)++; // Cannot change value

    // Constant Pointer
    int * const q = &a;
    // q++; // Cannot change address
    (*q)++; // Can change value at address
    cout << a << endl;

    int const * const r = &a; // Cannot change address & value
}