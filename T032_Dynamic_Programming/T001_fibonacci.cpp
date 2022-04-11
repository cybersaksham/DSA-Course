#include <iostream>
using namespace std;

// Brute Force
int fibSimple(int n) {
    if(n <= 1) return n;
    return fibSimple(n - 1) + fibSimple(n - 2);
}

// Memoization
int fibMemoizeHelper(int n, int *arr) {
    if(n <= 1) return n;
    if(arr[n] != -1) return arr[n];

    int a = fibMemoizeHelper(n - 1, arr);
    int b = fibMemoizeHelper(n - 2, arr);
    arr[n] = a + b;

    return arr[n];
}

int fibMemoize(int n) {
    int *arr = new int[n + 1];
    for(int i=0; i<=n; i++) arr[i] = -1;

    int ans = fibMemoizeHelper(n, arr);

    delete[] arr;
    return ans;
}

// Dynamic Programming
int fibDP(int n) {
    if(n <= 1) return n;

    int *arr = new int[n + 1];
    arr[0] = 0;
    arr[1] = 1;

    for(int i=2; i<=n; i++) arr[i] = arr[i - 1] + arr[i - 2];

    int ans = arr[n];
    delete[] arr;
    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << fibMemoize(n) << endl;
    cout << fibDP(n) << endl;
    cout << fibSimple(n) << endl;

    return 0;
}