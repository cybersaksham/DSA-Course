// Find sum of digits in an integer using recursion

#include <bits/stdc++.h>
using namespace std;

int digits(int a)
{
    if (a / 10 == 0) return abs(a);
    return abs(a % 10) + digits(a / 10);
}

int main()
{
    int a;
    cin >> a;

    cout << digits(a) << endl;

    return 0;
}