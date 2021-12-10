// Convert recursively a numeric string to its corresponding integer

#include <bits/stdc++.h>
using namespace std;

int convertInt(string s)
{
    if(s.size() == 0) return 0;
    return ((s[0] - '0') * pow(10, s.size() - 1)) + convertInt(s.substr(1));
}

int main()
{
    string s;
    cin >> s;

    cout << convertInt(s) << endl;

    return 0;
}