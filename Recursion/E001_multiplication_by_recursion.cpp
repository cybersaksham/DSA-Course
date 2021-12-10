// Calculate multiplication of 2 integers using recursion by using only addition & subtraction

#include <iostream>
using namespace std;

int multiplication(int a, int b)
{
    if (b == 0) return 0;
    else if (b == 1) return a;
    else if (b == -1) return -a;
    else if (b > 1) return a + multiplication(a, b - 1);
    return -a + multiplication(a, b + 1);
}

int main()
{
    int a, b;
    cin >> a >> b;

    cout << multiplication(a, b) << endl;

    return 0;
}