/*
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.
*/

#include <bits/stdc++.h>
using namespace std;

bool checkAB(string s)
{
    if(s.size() <= 1) return true;
    if(s.size() == 2) return !(s[0] == 'a' && s[1] == 'b');
    
    bool prevOut = checkAB(s.substr(1));
    if(!prevOut) return false;

    if(s[0] == 'a') return (s[1] == 'a' || (s[1] == 'b' && s[2] == 'b'));
    return (s[1] == 'a' || (s[1] == 'b' && s[2] == 'a'));
}

int main()
{
    string s;
    cin >> s;

    cout << ((checkAB(s) && s[0] == 'a') ? "Correct" : "Incorrect") << endl;
    return 0;
}