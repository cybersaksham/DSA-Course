/*
Given an array with N elements, you need to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in strictly increasing order.
Input Format

Line 1 : An integer N 
Line 2 : Elements of arrays separated by spaces
*/

#include <iostream>
using namespace std;

int lis(int const *arr, int n) {
    if(n <= 0) return 0;

    int *data = new int[n];
    data[n - 1] = 1;

    for(int i=n-2; i>=0; i--) {
        int a = data[i + 1];
        int b = 0;

        for(int j=i+1; j<n; j++) {
            if(arr[j] > arr[i]) b = max(b, data[j]);
        }

        data[i] = max(a, 1 + b);
    }
    int ans = data[0];

    delete[] data;
    return ans;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << lis(arr, n) << endl;

    delete[] arr;
    return 0;
}