/*
Remove all leaf nodes from a given Binary Tree. Leaf nodes are those nodes, which don't have any children.
Note : Root will also be a leaf node if it doesn't have left and right child.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
TreeNode<T> *TreeNode<T>::removeLeaf(TreeNode<T> *root)
{
    if (root == NULL)
        return root;

    if (root->left == NULL && root->right == NULL)
        return NULL;

    root->left = removeLeaf(root->left);
    root->right = removeLeaf(root->right);

    return root;
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();
    root = TreeNode<int>::removeLeaf(root);
    TreeNode<int>::printLevelOrder(root);

    TreeNode<int>::destroy(root);

    return 0;
}