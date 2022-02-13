/*
For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
Note:
All the node data will be unique and hence there will always exist a minimum and maximum node data.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
T TreeNode<T>::getMin(TreeNode<T> const *root)
{
    if (root == NULL)
        return -1;

    T left = TreeNode<T>::getMin(root->left);
    T right = TreeNode<T>::getMin(root->right);

    T minVal = min(left, right);

    if (minVal == -1)
        return root->data;
    else
        return min(minVal, root->data);
}

template <typename T>
T TreeNode<T>::getMax(TreeNode<T> const *root)
{
    if (root == NULL)
        return -1;

    T left = TreeNode<T>::getMax(root->left);
    T right = TreeNode<T>::getMax(root->right);

    return max(max(left, right), root->data);
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();

    cout << TreeNode<int>::getMin(root) << " " << TreeNode<int>::getMax(root) << endl;

    TreeNode<int>::destroy(root);

    return 0;
}