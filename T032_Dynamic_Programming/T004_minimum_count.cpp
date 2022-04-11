/*
Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
*/

#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

// Brute Force
int minCount(int n) {
    if(n <= 1) return n;

    int ans = INT_MAX;
    for(int i=1; i<=sqrt(n); i++) ans = min(ans, 1 + minCount(n - i * i));

    return ans;
}

// Memoization
int minCountMemoizeHelper(int n, int *arr) {
    if(n <= 1) return n;
    if(arr[n] != -1) return arr[n];

    int ans = INT_MAX;
    for(int i=1; i<=sqrt(n); i++) ans = min(ans, 1 + minCount(n - i * i));
    arr[n] = ans;

    return ans;
}

int minCountMemoize(int n) {
    int *arr = new int[n + 1];
    for(int i=0; i<=n; i++) arr[i] = -1;

    int ans = minCountMemoizeHelper(n, arr);

    delete[] arr;
    return ans;
}

// Dynamic Programming
int minCountDP(int n) {
    if(n <= 1) return n;

    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for(int i=2; i<=n; i++) {
        int ans = INT_MAX;
        for(int j=1; j<=sqrt(i); j++) ans = min(ans, 1 + arr[i - j * j]);
        arr[i] = ans;
    }

    int ans = arr[n];
    delete[] arr;
    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << minCountMemoize(n) << endl;
    cout << minCountDP(n) << endl;
    cout << minCount(n) << endl;

    return 0;
}