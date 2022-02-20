/*
Given a string S, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same, as in the input string.

Input format:
The first and only line of input contains a string, that denotes the value of S.

Output format :
The first and only line of output contains the updated string, as described in the task.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    unordered_map<int, int> map1;
    string snew = "";

    for (int i = 0; i < n; i++)
    {
        if (map1.count(s[i]) == 0)
            snew += s[i];
        map1[s[i]]++;
    }

    cout << snew << endl;

    return 0;
}