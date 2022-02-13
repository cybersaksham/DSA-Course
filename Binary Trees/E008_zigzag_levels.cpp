/*
Given a binary tree, print the zig zag order i.e print level 1 from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
Input format :
Elements in level order form (separated by space)
(If any node does not have left or right child, take -1 in its place)
*/

#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

template <typename T>
void TreeNode<T>::zigzagLevels(TreeNode<T> const *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<T> const *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    int i = 1;
    while (!pendingNodes.empty())
    {
        TreeNode const *node = pendingNodes.front();
        pendingNodes.pop();

        if (node == NULL)
        {
            cout << endl;
            i++;
            if (!pendingNodes.empty())
                pendingNodes.push(NULL);
            continue;
        }

        cout << node->data << " ";
        if (i % 2 == 0)
        {
            if (node->left)
                pendingNodes.push(node->left);
            if (node->right)
                pendingNodes.push(node->right);
        }
        else
        {
            if (node->right)
                pendingNodes.push(node->right);
            if (node->left)
                pendingNodes.push(node->left);
        }
    }
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();
    TreeNode<int>::zigzagLevels(root);

    TreeNode<int>::destroy(root);

    return 0;
}