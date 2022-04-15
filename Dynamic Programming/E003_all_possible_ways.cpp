/*
Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
For eg. if a = 10 and b = 2, only way to represent 10 as -
10 = 1^2 + 3^2

Hence, answer is 1.
Note : x^y represents x raise to the power y

Inout Format :
Two integers a and b (separated by space)
*/

#include <iostream>
#include <cmath>
using namespace std;

int ways(int a, int b) {
    int **data = new int *[a];
    for(int i=0; i<a; i++) data[i] = new int[a + 1];

    if(b == 1) data[a - 1][a] = 1;
    else data[a - 1][a] = 0;
    for(int i=0; i<a; i++) data[a - 1][i] = 0;

    for(int i=a-2; i>=0; i--) {
        for(int j=a; j>=0; j--) {
            int k = (int)pow(i + 1, b);
            int x = 0;
            if(k == j) x = 1;
            else if(k < j) x = data[i + 1][j - k];
            int y = data[i + 1][j];
            
            data[i][j] = x + y;
        }
    }

    int ans = data[0][a];

    for(int i=0; i<a; i++) delete[] data[i];
    delete[] data;

    return ans;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << ways(a, b) << endl;

    return 0;
}