// Recursively print steps for tower of hanoi
// For tower of hanoi see https://en.wikipedia.org/wiki/Tower_of_Hanoi

#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char s = 'a', char a = 'b', char d = 'c')
{
    if(n == 1) cout << s << " " << d << endl;
    else if(n == 2)
    {
        cout << s << " " << a << endl;
        cout << s << " " << d << endl;
        cout << a << " " << d << endl;
    }
    else
    {
        towerOfHanoi(n - 1, 'a', 'c', 'b');
        cout << s << " " << d << endl;
        towerOfHanoi(n - 1, 'b', 'a', 'c');
    }
}

int main()
{
    int n;
    cin >> n;

    towerOfHanoi(n);

    return 0;
}