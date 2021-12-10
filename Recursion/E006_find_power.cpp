// Find x^n using recursion

#include <iostream>
using namespace std;

float power(int x, int n)
{
    if(n == 0) return 1;
    else if (n == 1) return x;
    else if (n == -1) return 1.0 / x;
    if(n > 1) return x * power(x, n - 1);
    else return (1.0 / x) * power(x, n + 1);
}

int main()
{
    int x, n;
    cin >> x >> n;

    cout << power(x, n) << endl;

    return 0;
}