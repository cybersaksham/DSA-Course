// Compute recursively a new string in which all identical chars of old string seperated by '*'

#include <bits/stdc++.h>
using namespace std;

string seperateIdentical(string s)
{
    if(s.size() <= 1) return s;
    if(s[0] == s[1]) return s.substr(0, 1) + "*" + seperateIdentical(s.substr(1));
    else return s.substr(0, 1) + seperateIdentical(s.substr(1));
}

int main()
{
    string s;
    cin >> s;

    cout << seperateIdentical(s) << endl;

    return 0;
}