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

// Function 4
void sum(int *a, int size)
{
    int sum = 0;
    for(int i=0; i<size; i++) sum += *(a + i);
    cout << sum << endl;
}

int main()
{
    int i = 10;
    int *ptr = &i;

    print(ptr);

    cout << ptr << endl;
    incrementPtr(ptr);
    cout << ptr << endl; // Will not change

    cout << *ptr << endl;
    increment(ptr);
    cout << *ptr << endl; // Will change

    // Passing array in function
    int a[] = {1,2,3,4,5,6,7,8,9};
    sum(a, sizeof(a) / sizeof(int)); // From 0 to 8
    sum(a + 1, sizeof(a) / sizeof(int) - 5); // From 1 to 4

    return 0;
}