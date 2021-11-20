#include <iostream>
using namespace std;

int main()
{
    int i = 65;
    char c = i; // Implicit type casting
    cout << c << endl;

    // char *pc = &i; // Will give error
    int *p = &i;
    char *pc = (char*)p; // Explicit type casting

    // Stored in little endian system
    cout << p << endl;
    cout << *p << endl;
    cout << pc << endl;
    cout << pc + 1 << endl;
    cout << pc + 2 << endl;
    cout << pc + 3 << endl;

    // Character to int
    char c1 = 'B';
    char *pc1 = &c1;
    int *p1 = (int*)pc1;

    cout << p1 << endl;
    cout << *p1 << endl;
}