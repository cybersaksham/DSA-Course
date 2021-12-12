/*
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
*/

#include <bits/stdc++.h>
using namespace std;

int **subsets(int size, int k, int *arr)
{
    if(size == 0)
    {
        if(k == 0)
        {
            int **tmp = new int*[2];
            int *tmp1 = new int[1];
            int *tmp2 = new int[1];
            tmp1[0] = 1;
            tmp2[0] = 0;
            tmp[0] = tmp1;
            tmp[1] = tmp2;
            return tmp;
        }
        int **tmp = new int*[1];
        int *tmp1 = new int[1];
        tmp1[0] = 0;
        tmp[0] = tmp1;
        return tmp;
    }

    int **out1 = subsets(size - 1, k - arr[0], arr + 1);
    int **out2 = subsets(size - 1, k, arr + 1);

    int size1 = out1[0][0];
    int size2 = out2[0][0];

    int n = size1 + size2;

    int **out = new int*[n + 1];
    int *outTmp = new int[1];
    outTmp[0] = n;
    out[0] = outTmp;

    for(int i=0; i<size1; i++)
    {
        int tmpSize = out1[i + 1][0];
        int *tmp = new int[tmpSize + 2];
        tmp[0] = tmpSize + 1;
        tmp[1] = arr[0];
        for(int j=0; j<tmpSize; j++)
        {
            tmp[j + 2] = out1[i + 1][j + 1];
        }
        out[i + 1] = tmp;
    }

    for(int i=0; i<size2; i++)
    {
        int tmpSize = out2[i + 1][0];
        int *tmp = new int[tmpSize + 1];
        tmp[0] = tmpSize;
        for(int j=0; j<tmpSize; j++)
        {
            tmp[j + 1] = out2[i + 1][j + 1];
        }
        out[i + 1 + size1] = tmp;
    }

    return out;
}

int main()
{
    int n, k;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++) cin >> arr[i];

    cin >> k;

    int **subs = subsets(n, k, arr);
    for(int i=0; i<subs[0][0]; i++)
    {
        for(int j=0; j<subs[i + 1][0]; j++) cout << subs[i + 1][j + 1] << " ";
        cout << endl;
    }

    return 0;
}