/*
For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}. You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
Return 0 if the change isn't possible.

Input Format
The first line of the input contains an integer value N, which denotes the total number of denominations.
The second line of input contains N values, separated by a single space. These values denote the value of denomination.
The third line of the input contains an integer value, that denotes the value of V.
*/

#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define int long long

int ways(int n, int const *denominations, int v) {
    map<int, int*> data;

    for(int i=0; i<n; i++) data[denominations[i]] = new int[v + 1];
    for(int i=v; i>=0; i--) {
        if(i % denominations[n - 1] == 0) data[denominations[n - 1]][i] = 1;
        else data[denominations[n - 1]][i] = 0;
    }
    for(int i=0; i<n; i++) data[denominations[i]][0] = 1;

    for(int i=n-2; i>=0; i--) {
        for(int j=1; j<=v; j++) {
            int res = 0;
            for(int k=0; k<=j; k++) {
                if(k % denominations[i] == 0) res += data[denominations[i + 1]][j - k];
            }

            data[denominations[i]][j] = res;
        }
    }

    int ans = data[denominations[0]][v];

    for(int i=0; i<n; i++) delete[] data[denominations[i]];

    return ans;
}

signed main() {
    int n;
    cin >> n;

    int *denomimations = new int[n];
    for(int i=0; i<n; i++) cin >> denomimations[i];
    sort(denomimations, denomimations + n);

    int v;
    cin >> v;

    cout << ways(n, denomimations, v) << endl;
    
    delete[] denomimations;
    return 0;
}