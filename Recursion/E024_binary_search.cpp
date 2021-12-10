/*
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
*/

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int n, vector<int> arr, int x, int low, int high)
{
    if(high < low) return -1;

    int mid = low + (high - low) / 2;

    if(x == arr[mid]) return mid;
    else if(x < arr[mid]) return binarySearch(n, arr, x, low, mid - 1);
    else return binarySearch(n, arr, x, mid + 1, high);
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++) cin >> arr[i];

    int x;
    cin >> x;
    
    cout << binarySearch(n, arr, x, 0, n - 1) << endl;

    return 0;
}