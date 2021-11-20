#include <iostream>
using namespace std;

int main()
{
    int *ptr; // Stores garbage address

    cout << ptr << endl;
    // cout << *ptr << endl; // Garbage address may contain some secret memory

    // To avoid we should initialize a null pointer
    int *ptr2 = 0;

    cout << ptr2 << endl;
    cout << *ptr2 << endl; // Accessing value will give segmenatation fault

    return 0;
}