/*
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.

Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
*/

#include <iostream>
#include "BSTNode.h"
using namespace std;

void BSTNode::pairsum(BSTNode const *root, int data)
{
    if (root == NULL)
        return;

    stack<BSTNode const *> st1;
    stack<BSTNode const *> st2;

    st1.push(root);
    st2.push(root);

    BSTNode const *tmp1 = root->left;
    BSTNode const *tmp2 = root->right;
    while (true)
    {
        while (tmp1 != NULL)
        {
            st1.push(tmp1);
            tmp1 = tmp1->left;
        }

        while (tmp2 != NULL)
        {
            st2.push(tmp2);
            tmp2 = tmp2->right;
        }

        int a = st1.top()->data;
        int b = st2.top()->data;

        if (a >= b)
            break;

        if (a + b > data)
        {
            tmp2 = st2.top()->left;
            st2.pop();
        }
        else if (a + b < data)
        {
            tmp1 = st1.top()->right;
            st1.pop();
        }
        else
        {
            cout << a << " " << b << endl;
            tmp1 = st1.top()->right;
            st1.pop();
            tmp2 = st2.top()->left;
            st2.pop();
        }
    }
}

int main()
{
    BSTNode *root = BSTNode::takeInputLevelOrder();
    int data;
    cin >> data;

    BSTNode::pairsum(root, data);

    BSTNode::destroy(root);

    return 0;
}