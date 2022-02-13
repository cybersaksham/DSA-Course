/*
Given a binary tree, check if its balanced i.e. depth of left and right subtrees of every node differ by at max 1. Return true if given binary tree is balanced, false otherwise.
Input format :
Elements in level order form (separated by space). If any node does not have left or right child, take -1 in its place.
*/

#include <iostream>
#include "TreeNode.h"
using namespace std;

template <typename T>
bool TreeNode<T>::checkBalanced(TreeNode<T> const *root)
{
    if (root == NULL)
        return true;

    // Making static variable to keep track of depth of subtrees
    static int nodeHT = 0;
    nodeHT++;

    // Keeping current level information safe
    int tempHTLeft = nodeHT;
    int tempHTRight = nodeHT;

    // Calling on left subtree
    bool checkLeft = checkBalanced(root->left);
    // Stoting depth of left subtree in left variable
    int tempHT1 = nodeHT;
    nodeHT = tempHTLeft;
    tempHTLeft = tempHT1;

    // Calling on right subtree after updating static variable
    bool checkRight = checkBalanced(root->right);
    // Storing depth of right subtree in right variable
    tempHTRight = nodeHT;

    // Updating static variable with maximum depth amongst left and right
    nodeHT = max(tempHTLeft, tempHTRight);

    // Checking for balance
    if (abs(tempHTLeft - tempHTRight) > 1)
        return false;

    return checkLeft && checkRight;
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();
    cout << TreeNode<int>::checkBalanced(root) << endl;

    TreeNode<int>::destroy(root);

    return 0;
}