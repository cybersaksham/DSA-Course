/*
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
*/


#include <bits/stdc++.h>
using namespace std;

bool checkContaning(string s, string t)
{
    if(s.size() == 0) return t.size() == 0;
    if(t.size() == 0) return true;

    if(t[0] == s[0]) return checkContaning(s.substr(1), t.substr(1));
    return checkContaning(s.substr(1), t);
}

int main()
{
    string s, t;
    cin >> s >> t;

    cout << (checkContaning(s, t) ? "true" : "false") << endl;

    return 0;
}