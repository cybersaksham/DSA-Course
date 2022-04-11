/*
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count and return all possible ways in which the child can run-up to the stairs.
*/

#include <iostream>
using namespace std;

// Brute Force
int staircase(int n) {
    if(n <= 1) return 1;
    if(n == 2) return 2;
    return staircase(n - 1) + staircase(n - 2) + staircase(n - 3);
}

// Memoization
int staircaseMemoizeHelper(int n, int *arr) {
    if(n <= 1) return 1;
    if(n == 2) return 2;
    if(arr[n] != -1) return arr[n];

    int a = staircaseMemoizeHelper(n - 1, arr);
    int b = staircaseMemoizeHelper(n - 2, arr);
    int c = staircaseMemoizeHelper(n - 3, arr);

    arr[n] = a + b + c;
    return arr[n];
}

int staircaseMemoize(int n) {
    int *arr = new int[n + 1];
    for(int i=0; i<=n; i++) arr[i] = -1;
    
    int ans = staircaseMemoizeHelper(n, arr);

    delete[] arr;
    return ans;
}

// Dynamic Programming
int staircaseDP(int n) {
    if(n <= 1) return 1;
    if(n == 2) return 2;

    int *arr = new int[n + 1];
    arr[0] = 1;
    arr[1] = 1;
    arr[2] = 2;

    for(int i=3; i<=n; i++) arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    int ans = arr[n];

    delete[] arr;
    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << staircaseMemoize(n) << endl;
    cout << staircaseDP(n) << endl;
    cout << staircase(n) << endl;
    
    return 0;
}