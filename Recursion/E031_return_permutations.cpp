/*
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <bits/stdc++.h>
using namespace std;

int permutations(string s, string *subs)
{
    if(s.size() <= 0)
    {
        subs[0] = "";
        return 1;
    }

    int smallOut = permutations(s.substr(1), subs);

    for(int i=0; i<smallOut; i++)
    {
        for(int j=s.size()-1; j>=0; j--)
        {
            subs[i + j * smallOut] = subs[i].substr(0, j) + s[0] + subs[i].substr(j);
        }
    }

    return smallOut * s.size();
}

int main()
{
    string s;
    cin >> s;

    string *subs = new string[1000];

    int total = permutations(s, subs);

    for(int i=0; i<total; i++) cout << subs[i] << endl;

    return 0;
}