// Check a string is palindrome or not using recursion

#include <bits/stdc++.h>
using namespace std;

bool palindrome(string s)
{
    if (s.size() <= 1) return true;
    return (s[0] == s[s.size() - 1]) && palindrome(s.substr(1, s.size() - 2));
}

int main()
{
    string s;
    cin >> s;

    cout << (palindrome(s) ? "True" : "False") << endl;

    return 0;
}