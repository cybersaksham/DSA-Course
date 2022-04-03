#include <iostream>
#include <queue>
using namespace std;

void sortKSortedArray(int *arr, int n, int k) {
    priority_queue<int> pq;
    for(int i=0; i<k && i<n; i++) pq.push(arr[i]);

    int ptr = 0;
    for(int i=k; i<n; i++) {
        arr[ptr++] = pq.top();
        pq.pop();
        pq.push(arr[i]);
    }

    while(!pq.empty()) {
        arr[ptr++] = pq.top();
        pq.pop();
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    sortKSortedArray(arr, n, k);

    for(int i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;

    delete[] arr;

    return 0;
}