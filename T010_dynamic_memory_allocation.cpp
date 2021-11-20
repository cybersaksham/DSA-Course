#include <iostream>
using namespace std;

int main()
{
    // Single Variable
    int *p = new int;
    *p = 10;
    cout << p << " " << *p << endl;
    delete p;

    // 1D Array
    p = new int[10];
    for(int i=0; i<10; i++) p[i] = i;
    cout << p[0] << " " << *p << endl;
    cout << p[3] << " " << *(p + 3) << endl;
    delete [] p;

    // 2D Array
    // p = new int[m][n] // Not Allowed
    int **q = new int* [10];
    for(int i=0; i<10; i++) q[i] = new int [20];
    for(int i=0; i<10; i++) delete [] q[i];
    delete [] q;
}