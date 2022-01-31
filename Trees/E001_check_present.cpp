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
bool TreeNode<T>::isPresent(TreeNode<T> const *root, T data)
{
    if (root == NULL)
        return false;

    if (root->data == data)
        return true;

    for (int i = 0; i < root->children.size(); i++)
    {
        int isPr = TreeNode<T>::isPresent(root->children[i], data);

        if (isPr)
            return true;
    }

    return false;
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