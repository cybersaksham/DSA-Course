#include <iostream>
using namespace std;

int main()
{
    char A[] = "abc";

    char *ptr = &A[0];

    cout << A << " " << ptr << endl; // A will print until it finds null charcater \0

    // Character pointer
    char c1 = 'a';
    char *p2 = &c1;

    cout << p2 << endl; // Print till null character

    return 0;
}