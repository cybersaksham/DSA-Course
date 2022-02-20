/*
You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
If two or more elements contend for the maximum frequency, return the element which occurs in the array first.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format :
The first and only line of output contains most frequent element in the given array.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, int> map;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        map[a]++;
    }

    pair<int, int> maxElem(INT_MIN, INT_MIN);
    unordered_map<int, int>::iterator it;
    it = map.begin();
    while (it != map.end())
    {
        if (it->second >= maxElem.second)
        {
            maxElem.first = it->first;
            maxElem.second = it->second;
        }
        it++;
    }

    cout << maxElem.first << endl;

    return 0;
}