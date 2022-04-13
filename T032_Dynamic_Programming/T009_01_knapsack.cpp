/*
A thief robbing a store can carry a maximal weight of W into his knapsack. There are N items, and i-th item weigh 'Wi' and the value being 'Vi.' What would be the maximum value V, that the thief can steal?

Input Format :
The first line of the input contains an integer value N, which denotes the total number of items.
The second line of input contains the N number of weights separated by a single space.
The third line of input contains the N number of values separated by a single space.
The fourth line of the input contains an integer value W, which denotes the maximum weight the thief can steal.
*/

#include <iostream>
#include <climits>
using namespace std;

// Brute Force
int knapsack(int const *weights, int const *values, int n, int w) {
    if(n <= 0) return 0;

    int a = INT_MIN;
    if(weights[0] <= w) a = values[0] + knapsack(weights + 1, values + 1, n - 1, w - weights[0]);
    int b = knapsack(weights + 1, values + 1, n - 1, w);

    return max(a, b);
}

// Memoization
int knapsackMemoizeHelper(int const *weights, int const *values, int **data, int n, int w) {
    if(n <= 0) return 0;
    if(w <= 0) return 0;
    if(data[0][w] != -1) return data[0][w];

    int a = INT_MIN;
    if(weights[0] <= w) a = values[0] + knapsackMemoizeHelper(weights + 1, values + 1, data + 1, n - 1, w - weights[0]);
    int b = knapsackMemoizeHelper(weights + 1, values + 1, data + 1, n - 1, w);

    data[0][w] = max(a, b);

    return data[0][w];
}
int knapsackMemoize(int const *weights, int const *values, int n, int w) {
    int **data = new int*[n];
    for(int i=0; i<n; i++) {
        int *tmp = new int[w + 1];
        for(int j=0; j<=w; j++) tmp[j] = -1;
        data[i] = tmp;
    }

    int ans = knapsackMemoizeHelper(weights, values, data, n, w);

    for(int i=0; i<n; i++) delete[] data[i];
    delete[] data;

    return ans;
}

// Dynamic Programming
int knapsackDP(int const *weights, int const *values, int n, int w) {
    if(n <= 0) return 0;
    if(w <= 0) return 0;

    int **data = new int*[n];
    for(int i=0; i<n; i++) data[i] = new int[w + 1];

    for(int i=0; i<n; i++) data[i][0] = 0;
    for(int i=1; i<=w; i++) {
        if(weights[n - 1] <= i) data[n - 1][i] = values[n - 1];
        else data[n - 1][i] = 0;
    }

    for(int i=n-2; i>=0; i--) {
        for(int j=1; j<=w; j++) {
            int a = INT_MIN;
            if(weights[i] <= j) a = values[i] + data[i + 1][j - weights[i]];
            int b = data[i + 1][j];
            data[i][j] = max(a, b);
        }
    }

    int ans = data[0][w];

    for(int i=0; i<n; i++) delete[] data[i];
    delete[] data;

    return ans;
}

int main() {
    int n;
    cin >> n;

    if(n <= 0) return 0;

    int *weights = new int[n];
    for(int i=0; i<n; i++) cin >> weights[i];
    int *values = new int[n];
    for(int i=0; i<n; i++) cin >> values[i];

    int w;
    cin >> w;

    cout << knapsackMemoize(weights, values, n, w) << endl;
    cout << knapsackDP(weights, values, n, w) << endl;
    cout << knapsack(weights, values, n, w) << endl;

    delete[] weights;
    delete[] values;

    return 0;
}