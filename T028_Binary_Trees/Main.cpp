#include <iostream>
#include "TreeNode.h"
using namespace std;

int main()
{
    /*
    // Recursive Input & Printing
    // 1 2 4 -1 -1 5 -1 7 -1 -1 3 6 8 -1 -1 -1 -1
    TreeNode<int> *root = TreeNode<int>::takeInputRecursive();
    TreeNode<int>::printRecursively(root);
    TreeNode<int>::destroy(root);
    */

    /*
    // Level Order Input & Printing
    // 1 2 3 4 5 6 -1 -1 -1 -1 7 8 -1 -1 -1 -1 -1
    TreeNode<int> *root2 = TreeNode<int>::takeInputLevelOrder();
    TreeNode<int>::printLevelOrder(root2);

    cout << TreeNode<int>::countNodes(root2) << endl;
    cout << TreeNode<int>::height(root2) << endl;
    cout << TreeNode<int>::depth(root2, 7) << endl;
    cout << TreeNode<int>::depth(root2, 1) << endl;
    cout << TreeNode<int>::depth(root2, 15) << endl;
    cout << TreeNode<int>::depth(root2, 6) << endl;
    cout << TreeNode<int>::countLeaf(root2) << endl;
    TreeNode<int>::inorderTraversal(root2);
    TreeNode<int>::preorderTraversal(root2);
    TreeNode<int>::postorderTraversal(root2);
    cout << TreeNode<int>::diameter(root2) << endl;
    cout << TreeNode<int>::diameterBetter(root2) << endl;

    TreeNode<int>::destroy(root2);
    */

    /*
    int in[] = {4, 2, 5, 7, 1, 8, 6, 3};
    int pre[] = {1, 2, 4, 5, 7, 3, 6, 8};
    TreeNode<int> *root3 = TreeNode<int>::constructTreePreIn(in, pre, 8);
    TreeNode<int>::printLevelOrder(root3);
    TreeNode<int>::destroy(root3);
    */

    int in[] = {4, 2, 5, 7, 1, 8, 6, 3};
    int post[] = {4, 7, 5, 2, 8, 6, 3, 1};
    TreeNode<int> *root4 = TreeNode<int>::constructTreePostIn(in, post, 8);
    TreeNode<int>::printLevelOrder(root4);
    TreeNode<int>::destroy(root4);

    return 0;
}