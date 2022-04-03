/*
Given an array of integers, check whether it represents max-heap or not. Return true if the given array represents max-heap, else return false.

Input Format:
The first line of input contains an integer, that denotes the value of the size of the array. Let us denote it with the symbol N.
The following line contains N space separated integers, that denote the value of the elements of the array.
*/

#include <iostream>
using namespace std;

bool checkMaxHeap(int const *arr, int n) {
    for(int i=0; i<n; i++) {
        int lci = 2 * i + 1;
        int rci = 2 * i + 2;

        if(lci < n && arr[lci] > arr[i]) return false;
        if(rci < n && arr[rci] > arr[i]) return false;
    }

    return true;
}

int main() {
    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    cout << checkMaxHeap(arr, n) << endl;
    delete[] arr;

    return 0;
}