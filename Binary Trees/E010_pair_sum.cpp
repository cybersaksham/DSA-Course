/*
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Assume binary tree contains all unique elements.
Note : In a pair, print the smaller element first. Order of different pair doesn't matter.
Input format :
Line 1 : Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
Line 2 : Integer S
*/

#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;

vector<int> arr;
void makeArray(TreeNode<int> const *root)
{
    if (root == NULL)
        return;

    arr.push_back(root->data);
    makeArray(root->left);
    makeArray(root->right);
}

template <typename T>
void TreeNode<T>::pairSum(TreeNode const *root, int data)
{
    makeArray(root);

    int n = arr.size();
    sort(arr.begin(), arr.end());

    int i = 0, j = n - 1;
    while (i < j)
    {
        int a = arr[i], b = arr[j];

        if (a + b == data)
        {
            cout << a << " " << b << endl;
            i++;
            j--;
        }
        else if (a + b < data)
            i++;
        else
            j--;
    }
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();

    int data;
    cin >> data;

    TreeNode<int>::pairSum(root, data);

    TreeNode<int>::destroy(root);

    return 0;
}