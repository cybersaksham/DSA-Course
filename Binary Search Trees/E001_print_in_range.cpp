/*
Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
Print the elements in increasing order.
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line contains two integers, that denote the value of k1 and k2.

Output Format:
The first and only line of output prints the elements which are in range k1 and k2 (both inclusive). Print the elements in increasing order.
*/

#include <iostream>
#include "BSTNode.h"
using namespace std;

void BSTNode::printInRange(BSTNode const *root, int minRange, int maxRange)
{
    if (root == NULL)
        return;

    static const BSTNode *mainRoot = root;

    if (root->data > maxRange)
        printInRange(root->left, minRange, maxRange);
    else if (root->data < minRange)
        printInRange(root->right, minRange, maxRange);
    else
    {
        printInRange(root->left, minRange, maxRange);
        cout << root->data << " ";
        printInRange(root->right, minRange, maxRange);
    }

    if (mainRoot == root)
        cout << endl;
}

int main()
{
    BSTNode *root = BSTNode::takeInputLevelOrder();
    int minRange, maxRange;
    cin >> minRange >> maxRange;

    BSTNode::printInRange(root, minRange, maxRange);

    BSTNode::destroy(root);

    return 0;
}