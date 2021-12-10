// Return all combination which a mobile keypad can make by a given number
/*
For example:
let number is 23
2 has abc on it
3 has def on it

So combinations are:
ad ae af bd be bf cd ce cf
*/

#include <bits/stdc++.h>
using namespace std;

string keypad[] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int printKeypad(int n, string subs[])
{
    if(n == 0)
    {
        subs[0] = "";
        return 1;
    }
    int smallOut = printKeypad(n/10, subs);
    int k = (n % 10) - 2;

    if(k < 0 || smallOut == -1) return -1;

    for(int i=1; i<keypad[k].size(); i++)
    {
        for(int j=0; j<smallOut; j++)
        {
            subs[j + smallOut * i] = subs[j] + keypad[k][i];
        }
    }
    for(int j=0; j<smallOut; j++)
    {
        subs[j] = subs[j] + keypad[k][0];
    }

    return keypad[k].size() * smallOut;
}

int main()
{
    int n;
    cin >> n;

    string *subs = new string[100];
    int k = printKeypad(n, subs);

    if(k == -1) cout << "Invalid Number" << endl;
    else
    {
        for(int i=0; i<k; i++) cout << subs[i] << endl;
    }

    return 0;
}