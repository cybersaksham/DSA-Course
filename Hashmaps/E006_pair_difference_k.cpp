/*
You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
Note: Take absolute difference between the elements of the array.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.
The following line contains an integer, that denotes the value of K.

Output format :
The first and only line of output contains count of all such pairs which have an absolute difference of K.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n;

    unordered_map<int, int> counts;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        counts[a]++;
    }

    cin >> k;

    int total = 0;
    unordered_map<int, int>::iterator it = counts.begin();
    while (it != counts.end())
    {
        if (k == 0)
        {
            if (it->second > 1)
                total += ((it->second * (it->second - 1)) / 2);
        }
        else
        {
            if (counts.count(counts[it->first + k]) > 0)
                total += (it->second * counts[it->first + k]);
            if (counts.count(counts[it->first - k]) > 0)
                total += (it->second * counts[it->first - k]);
            counts[it->first] = 0;
        }

        it++;
    }

    cout << total << endl;

    return 0;
}