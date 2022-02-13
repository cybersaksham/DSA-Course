/*
For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.
Example:

For the above-depicted tree, when printed in a level order fashion, the output would look like:

10
20 30
40 50 60
Where each new line denotes the level in the tree.

Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.
*/

#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

template <typename T>
void TreeNode<T>::printLevels(TreeNode<T> const *root)
{
    if (root == NULL)
        return;

    queue<TreeNode<T> const *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    while (!pendingNodes.empty())
    {
        TreeNode const *node = pendingNodes.front();
        pendingNodes.pop();

        if (node == NULL)
        {
            cout << endl;
            if (!pendingNodes.empty())
                pendingNodes.push(NULL);
            continue;
        }

        cout << node->data << " ";
        if (node->left)
            pendingNodes.push(node->left);
        if (node->right)
            pendingNodes.push(node->right);
    }
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();
    TreeNode<int>::printLevels(root);

    TreeNode<int>::destroy(root);

    return 0;
}