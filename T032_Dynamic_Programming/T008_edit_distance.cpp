/*
You are given two strings S and T of lengths M and N, respectively. Find the 'Edit Distance' between the strings.
Edit Distance of two strings is the minimum number of steps required to make one string equal to the other. In order to do so, you can perform the following three operations:
1. Delete a character
2. Replace a character with another one
3. Insert a character

Note :
Strings don't contain spaces in between.
*/

#include <iostream>
using namespace std;

// Brute Force
int editDist(string const &s, string const &t) {
    int m = s.size(), n = t.size();
    if(m == 0) return n;
    if(n == 0) return m;

    if(s[0] == t[0]) return editDist(s.substr(1), t.substr(1));
    else {
        int a = editDist(s, t.substr(1)); // Delete
        int b = editDist(s.substr(1), t.substr(1)); // Replace
        int c = editDist(s.substr(1), t); // Insert
        return 1 + min(a, min(b, c));
    }
}

// Memoization
int editDistMemoizeHelper(string const &s, string const &t, int **data) {
    int m = s.size(), n = t.size();
    if(m == 0) return n;
    if(n == 0) return m;
    if(data[m][n] != -1) return data[m][n];

    int a = editDistMemoizeHelper(s, t.substr(1), data); // Delete
    int b = editDistMemoizeHelper(s.substr(1), t.substr(1), data); // Replace
    int c = editDistMemoizeHelper(s.substr(1), t, data); // Insert

    if(s[0] == t[0]) data[m][n] = b;
    else data[m][n] = 1 + min(a, min(b, c));

    return data[m][n];
}
int editDistMemoize(string const &s, string const &t) {
    int m = s.size(), n = t.size();

    int **data = new int*[m + 1];
    for(int i=0; i<=m; i++) {
        int *tmp = new int[n + 1];
        for(int j=0; j<=n; j++) tmp[j] = -1;
        data[i] = tmp;
    }

    int ans = editDistMemoizeHelper(s, t, data);

    for(int i=0; i<=m; i++) delete[] data[i];
    delete[] data;

    return ans;
}

// Dynamic Programming
int editDistDP(string const &s, string const &t) {
    int m = s.size(), n = t.size();

    int **data = new int*[m + 1];
    for(int i=0; i<=m; i++) data[i] = new int[n + 1];

    data[0][0] = 0;
    for(int i=1; i<=n; i++) data[0][i] = i;
    for(int i=1; i<=m; i++) data[i][0] = i;

    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(s[m - i] == t[n - j]) data[i][j] = data[i - 1][j - 1];
            else data[i][j] = 1 + min(data[i - 1][j - 1], min(data[i][j - 1], data[i - 1][j]));
        }
    }

    int ans = data[m][n];

    for(int i=0; i<=m; i++) delete[] data[i];
    delete[] data;

    return ans;
}

int main() {
    string s, t;
    cin >> s >> t;

    cout << editDistMemoize(s, t) << endl;
    cout << editDistDP(s, t) << endl;
    cout << editDist(s, t) << endl;

    return 0;
}