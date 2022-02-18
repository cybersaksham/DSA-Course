#include <iostream>
#include "BSTNode.h"
using namespace std;

int main()
{
    BSTNode *root = NULL;

    // Inserting
    root = BSTNode::insert(root, 4);
    root = BSTNode::insert(root, 2);
    root = BSTNode::insert(root, 6);
    root = BSTNode::insert(root, 1);
    root = BSTNode::insert(root, 3);
    root = BSTNode::insert(root, 5);
    root = BSTNode::insert(root, 7);
    BSTNode::printLevelOrder(root);

    // Deletion
    root = BSTNode::remove(root, 1);
    root = BSTNode::remove(root, 4);
    root = BSTNode::remove(root, 10);
    BSTNode::printLevelOrder(root);

    // Searching
    cout << BSTNode::hasNode(root, 1) << " " << BSTNode::hasNode(root, 3) << endl;

    // Inorder
    BSTNode::inorderTraversal(root);

    // Checking for bst
    cout << BSTNode::checkBST1(root) << endl;
    cout << BSTNode::checkBST2(root) << endl;
    cout << BSTNode::checkBST3(root) << endl;

    BSTNode::destroy(root);

    return 0;
}