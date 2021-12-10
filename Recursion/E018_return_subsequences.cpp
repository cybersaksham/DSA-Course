// Return all subsequences of an string recursively

#include <bits/stdc++.h>
using namespace std;

int subsequences(string s, string subs[])
{
    if(s.size() == 0)
    {
        subs[0] = "";
        return 1;
    }
    int smallOut = subsequences(s.substr(1), subs);
    for(int i=0; i<smallOut; i++)
    {
        subs[i + smallOut] = s[0] + subs[i];
    }
    return 2 * smallOut;
}

int main()
{
    string s;
    cin >> s;

    string *subs = new string[(int)pow(2, s.size())];
    int k = subsequences(s, subs);

    for(int i=0; i<k; i++) cout << subs[i] << endl;

    return 0;
}