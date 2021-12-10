// Compute recursively a new string in which all "x" of old string have been removed.

#include <bits/stdc++.h>
using namespace std;

string removeX(string s)
{
    if(s.size() == 0) return "";
    if(s[0] == 'x') return removeX(s.substr(1));
    else return s.substr(0, 1) + removeX(s.substr(1));
}

int main()
{
    string s;
    cin >> s;

    cout << removeX(s) << endl;

    return 0;
}