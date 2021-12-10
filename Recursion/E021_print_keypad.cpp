// Print all combination which a mobile keypad can make by a given number
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

void printKeypad(int n, string out = "")
{
    if(n == 0)
    {
        cout << out << endl;
        return;
    }

    int k = (n % 10) - 2;

    for(int i=0; i<keypad[k].size(); i++)
    {
        printKeypad(n / 10, keypad[k][i] + out);
    }
}

int checkNum(int n)
{
    while(n != 0)
    {
        if(n % 10 < 2) return 0;
        n /= 10;
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;

    if(!checkNum(n)) cout << "Invalid Number" << endl;
    else printKeypad(n);

    return 0;
}