/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to print the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. Just print them in different lines.

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw
*/

#include <bits/stdc++.h>
using namespace std;

void codes(string s, string out = "")
{
    if(s.size() <= 0)
    {
        cout << out << endl;
        return;
    }
    if(s.size() == 1)
    {
        cout << (out + (char)('a' + s[0] - '0' - 1)) << endl;
        return;
    }

    codes(s.substr(1), out + (char)('a' + s[0] - '0' - 1));

    int first = s[0] - '0';
    int second = s[1] - '0';
    int tmp = first * 10 + second;
    if(tmp <= 26) codes(s.substr(2), out + (char)('a' + tmp - 1));
}

int main()
{
    string s;
    cin >> s;
    
    codes(s);

    return 0;
}