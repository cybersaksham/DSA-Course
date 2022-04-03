/*
You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
Time complexity should be O(nlogk) and space complexity should be not more than O(k).
Order of elements in the output is not important.

Input Format :
Line 1 : Size of array (n), Integer k
Line 2 : Array elements (separated by space)
*/

#include <iostream>
#include <queue>
using namespace std;

pair<int *, int> kSmallestElems(int const *arr, int n, int k) {
    priority_queue<int> pq;
    for(int i=0; i<min(k, n); i++) pq.push(arr[i]);

    for(int i=k; i<n; i++) {
        if(arr[i] <= pq.top()) {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    int *ans = new int[min(k, n)];
    int ptr = 0;
    while(!pq.empty()) {
        ans[ptr++] = pq.top();
        pq.pop();
    }

    return {ans, min(k, n)};
}

int main() {
    int n, k;
    cin >> n >> k;

    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    pair<int *, int> ans = kSmallestElems(arr, n, k);
    for(int i=0; i<ans.second; i++) cout << ans.first[i] << " ";
    cout << endl;

    delete[] ans.first;
    delete[] arr;

    return 0;
}