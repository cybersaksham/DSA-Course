/*
A thief wants to loot houses. He knows the amount of money in each house. He cannot loot two consecutive houses. Find the maximum amount of money he can loot.

Input format :
The first line of input contains an integer value of 'n'. It is the total number of houses.
The second line of input contains 'n' integer values separated by a single space denoting the amount of money each house has.
*/

#include <iostream>
using namespace std;

int lootHouses(int const *money, int n) {
    if(n <= 0) return 0;

    int *data = new int[n + 1];
    data[n] = 0;
    data[n - 1] = money[n - 1];

    for(int i=n-2; i>=0; i--) data[i] = max(data[i + 1], money[i] + data[i + 2]);
    int ans = data[0];

    delete[] data;
    return ans;
}

int main() {
    int n;
    cin >> n;

    int *money = new int[n];
    for(int i=0; i<n; i++) cin >> money[i];

    cout << lootHouses(money, n) << endl;

    delete[] money;
    return 0;
}