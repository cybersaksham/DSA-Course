/*
Given a binary search tree and two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
LCA
LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants.

Note:
It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.

Note:
1. If out of 2 nodes only one node is present, return that node. 
2. If both are not present, return -1.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains two integers, denoting the value of data of two nodes of given BST.

Output Format:
The first and only line of output contains the data associated with the lowest common ancestor node.
*/

#include <iostream>
#include <list>
#include "BSTNode.h"
using namespace std;

int BSTNode::lca(BSTNode const *root, int data1, int data2)
{
    if (root == NULL)
        return -1;

    if (root->data == data1 || root->data == data2)
        return root->data;

    if (data1 < root->data && data2 < root->data)
        return lca(root->left, data1, data2);
    if (data1 > root->data && data2 > root->data)
        return lca(root->right, data1, data2);

    int leftData = lca(root->left, data1, data2);
    int rightData = lca(root->right, data1, data2);

    if (leftData == -1 && rightData == -1)
        return -1;
    if (leftData == -1)
        return rightData;
    if (rightData == -1)
        return leftData;

    return root->data;
}

int main()
{
    BSTNode *root = BSTNode::takeInputLevelOrder();
    int data1, data2;
    cin >> data1 >> data2;

    cout << BSTNode::lca(root, data1, data2) << endl;

    BSTNode::destroy(root);

    return 0;
}