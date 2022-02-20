/*
You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
Note:
1. Best solution takes O(n) time.
2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.

Input format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol n.
The following line contains n space separated integers, that denote the value of the elements of the array.

Output format:
The first and only line of output contains starting and ending element of the longest consecutive sequence. If the length of longest consecutive sequence, then just print the starting element.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int, bool> map1;
    unordered_map<int, int> indices;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        map1[a] = true;
        indices[a] = i;
    }

    int maxLen = 1, start = 0, minIndex = n;

    unordered_map<int, bool>::iterator it = map1.begin();
    while (it != map1.end())
    {
        if (it->second)
        {
            int startc = it->first;
            int len = 1;
            int a = it->first + 1;
            while (map1.count(a) > 0)
            {
                map1[a] = false;
                len++;
                a++;
            }
            a = it->first - 1;
            while (map1.count(a) > 0)
            {
                map1[a] = false;
                startc = a;
                len++;
                a--;
            }

            if (len > maxLen || (len == maxLen && indices[startc] < minIndex))
            {
                maxLen = len;
                start = startc;
                minIndex = indices[startc];
            }
        }
        it++;
    }

    cout << start << " " << (start + maxLen - 1) << endl;

    return 0;
}