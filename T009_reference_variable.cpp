#include <iostream>
using namespace std;

void increment(int& a) {a++;}

// Bad Practice because a is local variable which is going to be erased
int& func1()
{
    int a = 10;
    return a;
}

// Bad Practice because a is local variable which is going to be erased
int* func2()
{
    int a = 10;
    return &a;
}

int main()
{
    int i = 10;
    int& j = i; // j is not in memory only in symbol table pointing to address of i

    cout << &i << " " << &j << endl;
    cout << i << " " << j << endl;
    j++;
    cout << i << " " << j << endl;
    i++;
    cout << i << " " << j << endl;

    // int& k; // Invalid

    increment(i);
    cout << i << " " << j << endl;

    int& k = func1();
    // cout << k << endl; --> cannot access

    int* k1 = func2();
    cout << k1 << endl; // NULL pointer

    // int& p = 10; // Not Allowed
}