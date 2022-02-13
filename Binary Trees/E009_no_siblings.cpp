/*
For a given Binary Tree of type integer, print all the nodes without any siblings.
Input Format:
The first and the only line of input will contain the node data, all separated by a single space. Since -1 is used as an indication whether the left or right node data exist for root, it will not be a part of the node data.

Output Format:
The only line of output prints the node data in a top to down fashion with reference to the root. 
Node data in the left subtree will be printed first and then the right subtree.
A single space will separate them all.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
void TreeNode<T>::noSiblings(TreeNode<T> const *root)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    static TreeNode const *mainRoot = root;

    if (root->left == NULL)
        cout << root->right->data << " ";
    else if (root->right == NULL)
        cout << root->left->data << " ";

    noSiblings(root->left);
    noSiblings(root->right);

    if (root == mainRoot)
        cout << endl;
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();
    TreeNode<int>::noSiblings(root);

    TreeNode<int>::destroy(root);

    return 0;
}