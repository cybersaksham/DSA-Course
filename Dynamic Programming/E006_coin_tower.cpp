/*
Whis and Beerus are playing a new game today. They form a tower of N coins and make a move in alternate turns. Beerus plays first. In one step, the player can remove either 1,  X, or Y coins from the tower. The person to make the last move wins the game. Can you find out who wins the game?

Input format :
The first and the only line of input contains three integer values separated by a single space. They denote the value of N, X and Y, respectively.
*/

#include <iostream>
using namespace std;

bool whoWins(int n, int x, int y) {
    if(n <= 0) return false;
    if(n == 1) return true;

    bool *data = new bool[n];
    data[0] = true;

    for(int i=1; i<n; i++) {
        bool a = data[i - 1];
        bool b = false, c = false;
        if(i >= x) b = data[i - x];
        if(i >= y) c = data[i - y];
        data[i] = !(a && b && c);
    }

    bool ans = data[n - 1];

    delete[] data;
    return ans;
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    if(whoWins(n, x, y)) cout << "Beerus" << endl;
    else cout << "Whis" << endl;

    return 0;
}