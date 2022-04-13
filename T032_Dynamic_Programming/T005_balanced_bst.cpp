/*
Given an integer h, find the possible number of balanced binary trees of height h. You just need to return the count of possible binary trees which are balanced.
This number can be huge, so return output modulus 10^9 + 7.
*/

#include <iostream>
using namespace std;

// Brute Force
int balancedBST(int h) {
    if(h <= 1) return 1;

    int a = balancedBST(h - 1);
    int b = balancedBST(h - 2);

    return a*a + 2*a*b;
}

// Memoization
int balancedBSTMemoizeHelper(int h, int *arr) {
    if(h <= 1) return 1;
    if(arr[h] != -1) return arr[h];

    int a = balancedBSTMemoizeHelper(h - 1, arr);
    int b = balancedBSTMemoizeHelper(h - 2, arr);
    arr[h] = a*a + 2*a*b;

    return arr[h];
}

int balancedBSTMemoize(int h) {
    int *arr = new int[h + 1];
    for(int i=0; i<=h; i++) arr[i] = -1;

    int ans = balancedBSTMemoizeHelper(h, arr);

    delete[] arr;
    return ans;
}

// Dynamic Programming
int balancedBSTDP(int h) {
    if(h <= 1) return 1;

    int *arr = new int[h + 1];
    arr[0] = 1;
    arr[1] = 1;

    for(int i=2; i<=h; i++) {
        int a = arr[i - 1], b = arr[i - 2];
        arr[i] = a*a + 2*a*b;
    }
    int ans = arr[h];

    delete[] arr;
    return ans;
}

int main() {
    int h;
    cin >> h;

    cout << balancedBSTMemoize(h) << endl;
    cout << balancedBSTDP(h) << endl;
    cout << balancedBST(h) << endl;
    
    return 0;
}