// Compute recursively a new string in which all "pi" of old string replaced by "3.14"

#include <bits/stdc++.h>
using namespace std;

string replacePI(string s)
{
    if(s.size() <= 1) return s;
    if(s[0] == 'p' && s[1] == 'i') return "3.14" + replacePI(s.substr(2));
    else return s.substr(0, 1) + replacePI(s.substr(1));
}

int main()
{
    string s;
    cin >> s;

    cout << replacePI(s) << endl;

    return 0;
}