/*
An integer matrix of size (M x N) has been given. Find out the minimum cost to reach from the cell (0, 0) to (M - 1, N - 1).
From a cell (i,  j), you can move in three directions:
1. ((i + 1),  j) which is, "down"
2. (i, (j + 1)) which is, "to the right"
3. ((i+1), (j+1)) which is, "to the diagonal"

The cost of a path is defined as the sum of each cell's values through which the route passes.
*/

#include <iostream>
#include <climits>
using namespace std;

// Brute Force
int minCostHelper(int const* const*arr, int low1, int low2, int high1, int high2) {
    if(low1 > high1 || low2 > high2) return INT_MAX;
    if(low1 == high1 && low2 == high2) return arr[low1][low2];

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if(high1 > low1) x = minCostHelper(arr, low1 + 1, low2, high1, high2);
    if(high2 > low2) y = minCostHelper(arr, low1, low2 + 1, high1, high2);
    if(high1 > low1 && high2 > low2) z = minCostHelper(arr, low1 + 1, low2 + 1, high1, high2);

    return arr[low1][low2] + min(x, min(y, z));
}
int minCost(int const* const*arr, int m, int n) {
    return minCostHelper(arr, 0, 0, m - 1, n - 1);
}

// Memoization
int minCostMemoizeHelper(int const* const*arr, int **data, int low1, int low2, int high1, int high2) {
    if(low1 > high1 || low2 > high2) return INT_MAX;
    if(low1 == high1 && low2 == high2) return arr[low1][low2];
    if(data[low1][low2] != -1) return data[low1][low2];

    int x = INT_MAX, y = INT_MAX, z = INT_MAX;
    if(high1 > low1) x = minCostMemoizeHelper(arr, data, low1 + 1, low2, high1, high2);
    if(high2 > low2) y = minCostMemoizeHelper(arr, data, low1, low2 + 1, high1, high2);
    if(high1 > low1 && high2 > low2) z = minCostMemoizeHelper(arr, data, low1 + 1, low2 + 1, high1, high2);

    data[low1][low2] = arr[low1][low2] + min(x, min(y, z));

    return data[low1][low2];
}
int minCostMemoize(int const* const*arr, int m, int n) {
    int **data = new int*[m];
    for(int i=0; i<m; i++) {
        int *tmp = new int[n];
        for(int j=0; j<n; j++) tmp[j] = -1;
        data[i] = tmp;
    }

    int ans = minCostMemoizeHelper(arr, data, 0, 0, m - 1, n - 1);

    for(int i=0; i<m; i++) delete[] data[i];
    delete[] data;

    return ans;
}

// Dynamic Programming
int minCostDP(int const* const*arr, int m, int n) {
    if(m <= 0 || n <= 0) return INT_MAX;

    int **data = new int*[m];
    for(int i=0; i<m; i++) data[i] = new int[n];

    data[m - 1][n - 1] = arr[m - 1][n - 1];
    for(int i=n-2; i>=0; i--) data[m - 1][i] = arr[m - 1][i] + data[m - 1][i + 1];
    for(int i=m-2; i>=0; i--) data[i][n - 1] = arr[i][n - 1] + data[i + 1][n - 1];

    for(int i=m-2; i>=0; i--) {
        for(int j=n-2; j>=0; j--) {
            data[i][j] = arr[i][j] + min(data[i + 1][j], min(data[i][j + 1], data[i + 1][j + 1]));
        }
    }

    int ans = data[0][0];

    for(int i=0; i<m; i++) delete[] data[i];
    delete[] data;

    return ans;
}

int main() {
    int m, n;
    cin >> m >> n;

    int **arr = new int*[m];
    for(int i=0; i<m; i++) {
        int *tmp = new int[n];
        for(int j=0; j<n; j++) cin >> tmp[j];
        arr[i] = tmp;
    }

    cout << minCostMemoize(arr, m, n) << endl;
    cout << minCostDP(arr, m, n) << endl;
    cout << minCost(arr, m, n) << endl;

    for(int i=0; i<m; i++) delete[] arr[i];
    delete[] arr;

    return 0;
}