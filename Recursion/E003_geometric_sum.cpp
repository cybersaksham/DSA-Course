// Find geometric sum 1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^a) using recursion

#include <bits/stdc++.h>
using namespace std;

float sum(int a)
{
    if (a == 0) return 1;
    return (1 / pow(2, a)) + sum(a - 1);
}

int main()
{
    int a;
    cin >> a;

    cout << sum(a) << endl;

    return 0;
}