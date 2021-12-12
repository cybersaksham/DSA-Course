/*
Given an array A and an integer K, print all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print them in different lines.
*/

#include <bits/stdc++.h>
using namespace std;

void subsets(int size, int k, int *arr, int *subs)
{
    if(size == 0)
    {
        if(k == 0)
        {
            for(int i=0; i<subs[0]; i++) cout << subs[i + 1] << " ";
            cout << endl;
        }
        return;
    }

    subsets(size - 1, k, arr + 1, subs);
    subs[subs[0] + 1] = arr[0];
    subs[0]++;
    subsets(size - 1, k - arr[0], arr + 1, subs);
    subs[0]--;
}

int main()
{
    int n, k;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    cin >> k;

    int *subs = new int[n + 1];
    subs[0] = 0;

    subsets(n, k, arr, subs);

    return 0;
}