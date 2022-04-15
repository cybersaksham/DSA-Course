/*
Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s. You need to return the size of the square matrix with all 0s.

Input format :
The first line of the test case contains two integer values, 'N' and 'M', separated by a single space. They represent the 'rows' and 'columns' respectively.
Second-line onwards, the next 'N' lines or rows represent the ith row values.
Each of the ith rows constitutes column values separated by a single space (Either 0 or 1).
*/

#include <iostream>
using namespace std;

int maxSize(int **matrix, int n, int m) {
    if(n <= 0 || m <= 0) return 0;

    int **data = new int*[n];
    for(int i=0; i<n; i++) data[i] = new int[m];

    for(int i=0; i<m; i++) data[0][i] = ((matrix[0][i] == 0) ? 1 : 0);
    for(int i=0; i<n; i++) data[i][0] = ((matrix[i][0] == 0) ? 1 : 0);

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(matrix[i][j] == 1) data[i][j] = 0;
            else data[i][j] = 1 + min(data[i - 1][j - 1], min(data[i - 1][j], data[i][j - 1]));
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) ans = max(ans, data[i][j]);
    }

    for(int i=0; i<n; i++) delete[] data[i];
    delete[] data;

    return ans;
}

int main() {
    int m, n;
    cin >> n >> m;

    int **matrix = new int*[n];
    for(int i=0; i<n; i++) {
        int *tmp = new int[m];
        for(int j=0; j<m; j++) cin >> tmp[j];
        matrix[i] = tmp;
    }
    
    cout << maxSize(matrix, n, m) << endl;

    for(int i=0; i<n; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}