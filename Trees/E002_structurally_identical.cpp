/*
Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.

Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line contains an integer, that denotes the value of x.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
bool TreeNode<T>::areIdentical(TreeNode<T> const *root1, TreeNode<T> const *root2)
{
    if (root1 == NULL || root2 == NULL)
        return root1 == NULL && root2 == NULL;

    if (root1->children.size() != root2->children.size())
        return false;

    for (int i = 0; i < root1->children.size(); i++)
    {
        bool isChildIdentical = areIdentical(root1->children[i], root2->children[i]);
        if (!isChildIdentical)
            return false;
    }

    return root1->data == root2->data;
}

int main()
{
    TreeNode<int> *root1 = TreeNode<int>::takeInputLevelOrder();
    TreeNode<int> *root2 = TreeNode<int>::takeInputLevelOrder();

    cout << TreeNode<int>::areIdentical(root1, root2) << endl;

    TreeNode<int>::destroy(root1);
    TreeNode<int>::destroy(root2);

    return 0;
}