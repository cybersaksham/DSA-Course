// Find all natural numbers upto a using recursion

#include <iostream>
using namespace std;

void nums(int a)
{
    if (a <= 1) cout << 1 << " ";
    else
    {
        nums(a - 1);
        cout << a << " ";
    }
}

int main()
{
    int a;
    cin >> a;

    nums(a);
    cout << endl;

    return 0;
}