/*
Given an integer array (of length n), find and return all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
*/

#include <bits/stdc++.h>
using namespace std;

int subsets(int size, int *arr, int **subs)
{
    if(size == 0)
    {
        int *tmp = new int[1];
        tmp[0] = 0;
        subs[0] = tmp;
        return 1;
    }

    int smallSize = subsets(size - 1, arr + 1, subs);

    for(int i=0; i<smallSize; i++)
    {
        int *tmp = new int[subs[i][0] + 2];
        tmp[0] = subs[i][0] + 1;
        tmp[1] = arr[0];
        for(int j=0; j<subs[i][0]; j++)
        {
            tmp[j + 2] = subs[i][j + 1];
        }
        subs[i + smallSize] = tmp;
    }

    return 2 * smallSize;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    int **subs = new int*[(int)pow(2, n)];

    int k = subsets(n, arr, subs);

    for(int i=0; i<k; i++)
    {
        for(int j=0; j<subs[i][0]; j++) cout << subs[i][j + 1] << " ";
        cout << endl;
    }

    return 0;
}