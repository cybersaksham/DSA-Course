/*
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output format:
The first and only line of output contains the height of the largest BST.
*/

#include <iostream>
#include <list>
#include "BSTNode.h"
using namespace std;

Combine BSTNode::largstBSTHelp(BSTNode const *root)
{
    if (root == NULL)
    {
        Combine newCombine(INT_MAX, INT_MIN, 0, true);
        return newCombine;
    }

    Combine leftCombine = largstBSTHelp(root->left);
    Combine rightCombine = largstBSTHelp(root->right);

    int minElem = min(root->data, min(leftCombine.minimum, rightCombine.minimum));
    int maxElem = max(root->data, max(leftCombine.maximum, rightCombine.maximum));
    int ht = max(leftCombine.height, rightCombine.height);
    bool isBST = false;

    if (leftCombine.isBST && rightCombine.isBST)
    {
        if (leftCombine.maximum < root->data && rightCombine.minimum > root->data)
        {
            isBST = true;
            ht += 1;
        }
    }

    Combine newCombine(minElem, maxElem, ht, isBST);
    return newCombine;
}

int BSTNode::largstBST(BSTNode const *root)
{
    return largstBSTHelp(root).height;
}

int main()
{
    BSTNode *root = BSTNode::takeInputLevelOrder();

    cout << BSTNode::largstBST(root) << endl;

    BSTNode::destroy(root);

    return 0;
}