// Find total no of zeros in an integer using recursion

#include <iostream>
using namespace std;

int zeros(int a)
{
    if (a / 10 == 0) return a == 0;
    if(a % 10 == 0) return 1 + zeros(a / 10);
    else return zeros(a / 10);
}

int main()
{
    int a;
    cin >> a;

    cout << zeros(a) << endl;

    return 0;
}