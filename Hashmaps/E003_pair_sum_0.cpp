/*
Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
Note: Array A can contain duplicate elements as well.

Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output format :
The first and only line of output contains the count of pair of elements in the array which sum up to 0.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> map1;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        map1[a]++;
    }

    int total = 0;
    unordered_map<int, int>::iterator it;
    it = map1.begin();
    while (it != map1.end())
    {
        if (map1.count(-1 * it->first) > 0)
        {
            total += it->second * map1[-1 * it->first];
            map1[it->first] = 0;
            map1[-1 * it->first] = 0;
        }
        it++;
    }

    cout << total << endl;

    return 0;
}