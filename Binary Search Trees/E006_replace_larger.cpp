/*
Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.

Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
*/

#include <iostream>
#include "BSTNode.h"
using namespace std;

void BSTNode::replaceLarger(BSTNode *root, int pendingAmt = 0)
{
    if (root == NULL)
        return;

    replaceLarger(root->right, pendingAmt);

    if (root->right)
        root->data += root->right->data;
    else
        root->data += pendingAmt;

    replaceLarger(root->left, root->data);
}

int main()
{
    BSTNode *root = BSTNode::takeInputLevelOrder();
    BSTNode::replaceLarger(root);
    BSTNode::printLevelOrder(root);

    BSTNode::destroy(root);

    return 0;
}