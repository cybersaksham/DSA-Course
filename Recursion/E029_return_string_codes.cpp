/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.

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

int codes(string s, string *subs)
{
    if(s.size() <= 0)
    {
        subs[0] = "";
        return 1;
    }
    if(s.size() == 1)
    {
        subs[0] = (char)('a' + s[0] - '0' - 1);
        return 1;
    }

    int smallOut = codes(s.substr(1), subs);
    int count = 0;

    for(int i=0; i<smallOut; i++)
    {
        int first = s[0] - '0';
        int second = subs[i][0] - 'a' + 1;
        if(second <= 9)
        {
            int tmp = first * 10 + second;
            if(tmp <= 26) subs[smallOut + count] = (char)('a' + tmp - 1) + subs[i].substr(1);
            count++;
        }
        subs[i] = (char)('a' + first - 1) + subs[i];
    }

    return smallOut + count;
}

int main()
{
    string s;
    cin >> s;

    string *subs = new string[1000];

    int total = codes(s, subs);

    for(int i=0; i<total; i++) cout << subs[i] << endl;

    return 0;
}