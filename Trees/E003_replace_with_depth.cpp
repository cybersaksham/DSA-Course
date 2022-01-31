/*
You are given a generic tree. You have to replace each node with its depth value.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
void TreeNode<T>::replaceWithDepth(TreeNode<T> *root)
{
    if (root == NULL)
        return;

    static int depth = -1;
    depth++;

    root->data = depth;

    for (int i = 0; i < root->children.size(); i++)
    {
        replaceWithDepth(root->children[i]);
    }

    depth--;
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();

    TreeNode<int>::replaceWithDepth(root);
    TreeNode<int>::printLevelOrder(root);

    TreeNode<int>::destroy(root);

    return 0;
}