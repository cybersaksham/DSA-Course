/*
Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).

Input Format :
Line 1 : Integer K
Line 2 : Arrays 1 size (n1)
Line 3 : Array 1 elements (separated by space)
Line 4 : Array 2 size (n2)
and so on for next arrays
*/

#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

class Triplet{
public:
    int first, second, third;
    Triplet(int a, int b, int c) : first(a), second(b), third(c) {}
};

bool compFunc(Triplet const &p1, Triplet const &p2) {
    return p1.first > p2.first;
}

vector<int> mergekSortedArrays(vector<vector<int>> const &arrays) {
    int k = arrays.size();
    vector<int> sizes(k);
    int totalSize = 0;
    for(int i=0; i<k; i++) {
        sizes[i] = arrays[i].size();
        totalSize += arrays[i].size();
    }

    priority_queue<Triplet, vector<Triplet>, function<bool(Triplet const &, Triplet const &)>> pq(compFunc);
    for(int i=0; i<k; i++) {
        if(sizes[i] > 0) pq.push(Triplet(arrays[i][0], i, 0));
    }

    int ptr = 0;
    vector<int> ans(totalSize);
    while(!pq.empty()) {
        Triplet tmp = pq.top();
        pq.pop();
        ans[ptr++] = tmp.first;
        if(tmp.third < sizes[tmp.second] - 1) pq.push(Triplet(arrays[tmp.second][tmp.third + 1], tmp.second, tmp.third + 1));
    }

    return ans;
}

int main() {
    int k;
    cin >> k;

    vector<vector<int>> arrays(k);
    for(int i=0; i<k; i++) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for(int i=0; i<n; i++) cin >> arr[i];

        arrays[i] = arr;
    }

    vector<int> ans = mergekSortedArrays(arrays);
    for(int i=0; i<ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    
    return 0;
}