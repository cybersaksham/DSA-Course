/*
Gary has two string S and V. Now Gary wants to know the length shortest subsequence in S such that it is not a subsequence in V.
Note: input data will be such so there will always be a solution.

Input Format :
Line 1 : String S of length N (1 <= N <= 1000)
Line 2 : String V of length M (1 <= M <= 1000)
*/

#include <iostream>
#include <climits>
using namespace std;

int shortestSub(string const &s, string const &t) {
    int m = s.size(), n = t.size();
    if(m <= 0) return 0;
    if(n <= 0) return 1;

    int **data = new int*[m];
    for(int i=0; i<m; i++) data[i] = new int[n + 1];

    data[m - 1][n - 1] = ((s[m - 1] == t[n - 1]) ? 0 : 1);
    for(int i=n-2; i>=0; i--) {
        if(s[m - 1] == t[i]) data[m - 1][i] = INT_MAX - 1;
        else data[m - 1][i] = data[m - 1][i + 1];
    }

    for(int i=m-2; i>=0; i--) data[i + 1][n] = 1;

    for(int i=m-2; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            if(s[i] == t[j]) data[i + 1][n] = 1 + data[i + 1][j + 1];
            data[i][j] = min(data[i + 1][j], data[i + 1][n]);
        }
    }

    int ans = data[0][0];

    for(int i=0; i<m; i++) delete[] data[i];
    delete[] data;

    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << shortestSub(s, t) << endl;

    return 0;
}