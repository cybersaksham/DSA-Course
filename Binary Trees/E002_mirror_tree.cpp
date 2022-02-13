/*
For a given Binary Tree of type integer, update it with its corresponding mirror image.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
void TreeNode<T>::mirrorTree(TreeNode<T> *root)
{
    if (root == NULL)
        return;

    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;

    TreeNode<T>::mirrorTree(root->left);
    TreeNode<T>::mirrorTree(root->right);
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();

    TreeNode<int>::mirrorTree(root);
    TreeNode<int>::printLevelOrder(root);

    TreeNode<int>::destroy(root);

    return 0;
}