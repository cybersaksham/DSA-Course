/*
For a given Binary Tree of type integer and a number X, find whether a node exists in the tree with data X or not.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
bool TreeNode<T>::isPresent(TreeNode<T> const *root, T data)
{
    if (root == NULL)
        return false;

    if (root->data == data)
        return true;

    bool isPrLeft = TreeNode<T>::isPresent(root->left, data);
    bool isPrRight = TreeNode<T>::isPresent(root->right, data);

    return isPrLeft || isPrRight;
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();

    int data;
    cin >> data;
    cout << TreeNode<int>::isPresent(root, data) << endl;

    TreeNode<int>::destroy(root);

    return 0;
}