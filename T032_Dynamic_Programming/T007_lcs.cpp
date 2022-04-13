/*
Find longest common subsequence of 2 input strings
*/

#include <iostream>
#include <climits>
using namespace std;

// Brute Force
int lcs(string s, string t) {
    int m = s.size(), n = t.size();
    if(m <= 0 || n <= 0) return 0;

    if(s[0] == t[0]) return 1 + lcs(s.substr(1), t.substr(1));
    else return max(lcs(s, t.substr(1)), lcs(s.substr(1), t));
}

// Memoization
int lcsMemoizehelper(string s, string t, int a, int b, int **data) {
    int m = s.size(), n = t.size();
    if(m <= 0 || n <= 0) return 0;
    if(a < 0 || b < 0) return 0;
    if(a >= m || b >= n) return 0;
    if(data[a][b] != -1) return data[a][b];

    int p = lcsMemoizehelper(s, t, a + 1, b + 1, data);
    int q = lcsMemoizehelper(s, t, a + 1, b, data);
    int r = lcsMemoizehelper(s, t, a, b + 1, data);

    if(s[a] == t[b]) data[a][b] = 1 + p;
    else data[a][b] = max(q, r);

    return data[a][b];
}
int lcsMemoize(string s, string t) {
    int m = s.size(), n = t.size();

    int **data = new int*[m];
    for(int i=0; i<m; i++) {
        int *tmp = new int[n];
        for(int j=0; j<n; j++) tmp[j] = -1;
        data[i] = tmp;
    }

    int ans = lcsMemoizehelper(s, t, 0, 0, data);

    for(int i=0; i<m; i++) delete[] data[i];
    delete[] data;

    return ans;
}

// Dynamic Programming
int lcsDP(string s, string t) {
    int m = s.size(), n = t.size();
    if(m <= 0 || n <= 0) return 0;

    int **data = new int*[m];
    for(int i=0; i<m; i++) data[i] = new int[n];

    if(s[m - 1] == t[n - 1]) data[m - 1][n - 1] = 1;
    else data[m - 1][n - 1] = 0;

    for(int i=n-2; i>=0; i--) {
        if(s[m - 1] == t[i]) data[m - 1][i] = 1;
        else data[m - 1][i] = data[m - 1][i + 1];
    }
    for(int i=m-2; i>=0; i--) {
        if(s[i] == t[n - 1]) data[i][n - 1] = 1;
        else data[i][n - 1] = data[i + 1][n - 1];
    }

    for(int i=m-2; i>=0; i--) {
        for(int j=n-2; j>=0; j--) {
            if(s[i] == t[j]) data[i][j] = 1 + data[i + 1][j + 1];
            else data[i][j] = max(data[i + 1][j], data[i][j + 1]);
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

    cout << lcsMemoize(s, t) << endl;
    cout << lcsDP(s, t) << endl;
    cout << lcs(s, t) << endl;

    return 0;
}