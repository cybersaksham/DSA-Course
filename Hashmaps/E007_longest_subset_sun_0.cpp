/*
Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.

Output Format
The first and only line of output contains length of the longest subarray whose sum is zero.
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0, maxLen = 0, start = n;
    unordered_map<int, int> sums;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sums.count(sum) == 0)
            sums[sum] = i;
        else
        {
            int len = i - sums[sum];
            int startc = sums[sum] + 1;

            if (len > maxLen || (len == maxLen && startc < start))
            {
                maxLen = len;
                start = startc;
            }
        }
    }

    for (int i = start; i < start + maxLen; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}