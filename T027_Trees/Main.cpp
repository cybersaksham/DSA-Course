#include <iostream>
#include "TreeNode.h"
using namespace std;

int main()
{
    /*
    // Recursive Input & Printing
    // 1 3 2 2 5 0 6 0 3 2 7 0 8 1 9 0 4 0
    TreeNode<int> *root = TreeNode<int>::takeInputRecursive();
    TreeNode<int>::printRecursively(root);
    TreeNode<int>::destroy(root);
    */

    // Level Order Input & Printing
    // 1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
    TreeNode<int> *root2 = TreeNode<int>::takeInputLevelOrder();
    TreeNode<int>::printLevelOrder(root2);

    cout << TreeNode<int>::countNodes(root2) << endl;
    cout << TreeNode<int>::height(root2) << endl;
    cout << TreeNode<int>::depth(root2, 7) << endl;
    cout << TreeNode<int>::depth(root2, 1) << endl;
    cout << TreeNode<int>::depth(root2, 15) << endl;
    cout << TreeNode<int>::depth(root2, 6) << endl;
    cout << TreeNode<int>::countLeaf(root2) << endl;
    TreeNode<int>::preorderTraversal(root2);
    TreeNode<int>::postorderTraversal(root2);

    TreeNode<int>::destroy(root2);

    return 0;
}