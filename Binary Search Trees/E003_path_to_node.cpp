/*
Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
Note: Assume that BST contains all unique elements.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of k.

Output Format :
The first line and only line of output prints the data of the nodes in the path from node k to root. The data of the nodes is separated by single space.
*/

#include <iostream>
#include <list>
#include "BSTNode.h"
using namespace std;

void BSTNode::pathToNode(BSTNode const *root, int data)
{
    if (root == NULL)
        return;

    static BSTNode const *mainRoot = root;

    if (data < root->data)
        pathToNode(root->left, data);
    else if (data > root->data)
        pathToNode(root->right, data);

    cout << root->data << " ";

    if (root == mainRoot)
        cout << endl;
}

int main()
{
    BSTNode *root = BSTNode::takeInputLevelOrder();
    int data;
    cin >> data;

    BSTNode::pathToNode(root, data);

    BSTNode::destroy(root);

    return 0;
}