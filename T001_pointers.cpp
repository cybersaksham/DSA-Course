#include <iostream>
using namespace std;

int main()
{
    int i = 10;
    int *ptr = &i; // Stores address of i

    cout << &i << endl;
    cout << ptr << endl;
    cout << *ptr << endl;

    return 0;
}