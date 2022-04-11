/*
Given a positive integer 'n',  find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
1.) Subtract 1 from it. (n = n - ­1) ,
2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).
*/

#include <iostream>
#include <climits>
using namespace std;

// Brute Force
int minSteps(int n) {
    if(n < 0) return INT_MAX;
    if(n == 1) return 0;

    int a = minSteps(n - 1);
    int b = INT_MAX, c = INT_MAX;
    if(n % 2 == 0) b = minSteps(n / 2);
    if(n % 3 == 0) c = minSteps(n / 3);

    return 1 + min(a, min(b, c));
}

// Memoization
int minStepsMemoizeHelper(int n, int *arr) {
    if(n < 0) return INT_MAX;
    if(n == 1) return 0;
    if(arr[n] != -1) return arr[n];

    int a = minSteps(n - 1);
    int b = INT_MAX, c = INT_MAX;
    if(n % 2 == 0) b = minSteps(n / 2);
    if(n % 3 == 0) c = minSteps(n / 3);

    arr[n] = 1 + min(a, min(b, c));
    return arr[n];
}

int minStepsMemoize(int n) {
    int *arr = new int[n + 1];
    for(int i=0; i<=n; i++) arr[i] = -1;

    int ans = minStepsMemoizeHelper(n, arr);

    delete[] arr;
    return ans;
}

// Dynamic Programming
int minStepsDP(int n) {
    if(n < 0) return INT_MAX;
    if(n == 1) return 0;

    int *arr = new int[n + 1];
    arr[0] = INT_MAX;
    arr[1] = 0;

    for(int i=2; i<=n; i++) {
        int a = arr[i - 1];
        int b = INT_MAX, c = INT_MAX;
        if(i % 2 == 0) b = arr[i / 2];
        if(i % 3 == 0) c = arr[i / 3];
        arr[i] = 1 + min(a, min(b, c));
    }

    int ans = arr[n];
    delete[] arr;
    return ans;
}

int main() {
    int n;
    cin >> n;

    cout << minStepsMemoize(n) << endl;
    cout << minStepsDP(n) << endl;
    cout << minSteps(n) << endl;

    return 0;
}