/*
Given an input string, find and return all possible permutations of the input string.
Note:
The input string may contain the same characters, so there will also be the same permutations.
The order of permutations doesn’t matter.

Sample Input 1:
cba

Sample Output 1:
abc
acb
bac
bca
cab
cba
*/

#include <bits/stdc++.h>
using namespace std;

void permutations(string s, string out = "")
{
    if(s.size() <= 0)
    {
        cout << out << endl;
        return;
    }

    for(int i=0; i<=out.size(); i++)
    {
        permutations(s.substr(1), out.substr(0, i) + s[0] + out.substr(i));
    }
}

int main()
{
    string s;
    cin >> s;

    permutations(s);

    return 0;
}