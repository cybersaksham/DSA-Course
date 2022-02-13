#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode
{
    T data;
    TreeNode *left;
    TreeNode *right;

    // Find diameter by better approach
    static pair<int, int> diameterBetterHelp(TreeNode const *root)
    {
        if (root == NULL)
        {
            pair<int, int> p;
            p.first = 0;
            p.second = 0;
            return p;
        }

        pair<int, int> leftData = diameterBetterHelp(root->left);
        pair<int, int> rightData = diameterBetterHelp(root->right);

        pair<int, int> p;
        p.first = 1 + max(leftData.first, rightData.first);
        p.second = max(leftData.first + rightData.first, max(leftData.second, rightData.second));

        return p;
    }

    // Construct tree from inorder and preorder traversal
    static TreeNode *constructTreePreInHelp(int const *in, int const *pre, int inS, int inE, int preS, int preE)
    {
        if (inS > inE || preS > preE || inS < 0 || inE < 0 || preS < 0 || preE < 0)
            return NULL;

        TreeNode *root = new TreeNode(pre[preS]);

        int rootInd = -1;
        for (int i = inS; i <= inE; i++)
        {
            if (in[i] == pre[preS])
            {
                rootInd = i;
                break;
            }
        }
        if (rootInd == -1)
            return NULL;

        int leftInS = inS;
        int leftInE = rootInd - 1;
        int leftPreS = preS + 1;
        int leftPreE = leftInE - leftInS + leftPreS;
        TreeNode *leftTree = constructTreePreInHelp(in, pre, leftInS, leftInE, leftPreS, leftPreE);

        int rightInS = rootInd + 1;
        int rightInE = inE;
        int rightPreS = leftPreE + 1;
        int rightPreE = preE;
        TreeNode *rightTree = constructTreePreInHelp(in, pre, rightInS, rightInE, rightPreS, rightPreE);

        root->left = leftTree;
        root->right = rightTree;

        return root;
    }

    // Construct tree from inorder and postorder traversal
    static TreeNode *constructTreePostInHelp(int const *in, int const *post, int inS, int inE, int postS, int postE)
    {
        if (inS > inE || postS > postE || inS < 0 || inE < 0 || postS < 0 || postE < 0)
            return NULL;

        TreeNode *root = new TreeNode(post[postE]);

        int rootInd = -1;
        for (int i = inS; i <= inE; i++)
        {
            if (in[i] == post[postE])
            {
                rootInd = i;
                break;
            }
        }
        if (rootInd == -1)
            return NULL;

        int leftInS = inS;
        int leftInE = rootInd - 1;
        int leftPostS = postS;
        int leftPostE = leftInE - leftInS + leftPostS;
        TreeNode *leftTree = constructTreePostInHelp(in, post, leftInS, leftInE, leftPostS, leftPostE);

        int rightInS = rootInd + 1;
        int rightInE = inE;
        int rightPostS = leftPostE + 1;
        int rightPostE = postE - 1;
        TreeNode *rightTree = constructTreePostInHelp(in, post, rightInS, rightInE, rightPostS, rightPostE);

        root->left = leftTree;
        root->right = rightTree;

        return root;
    }

public:
    // Constructor
    TreeNode(T data) : data(data), left(NULL), right(NULL) {}
    TreeNode(T data, TreeNode *left, TreeNode *right) : data(data), left(left), right(right) {}

    // Take input recursively
    static TreeNode *takeInputRecursive()
    {
        T data;
        int n;

        cout << "Enter data = ";
        cin >> data;

        if (data == -1)
            return NULL;

        TreeNode *root = new TreeNode(data, takeInputRecursive(), takeInputRecursive());
        cout << endl;
        return root;
    }

    // Print Recursively
    static void printRecursively(TreeNode const *root)
    {
        if (root == NULL)
            return;

        cout << root->data << ": ";

        if (root->left != NULL)
        {
            cout << "L -> " << root->left->data;
            if (root->right != NULL)
                cout << ", ";
        }
        if (root->right != NULL)
        {
            cout << "R -> " << root->right->data;
        }
        cout << endl;

        printRecursively(root->left);
        printRecursively(root->right);
    }

    // Take input in level order
    static TreeNode *takeInputLevelOrder()
    {
        T data, leftData, rightData;

        cout << "Enter data of root = ";
        cin >> data;

        if (data == -1)
            return NULL;

        TreeNode *root = new TreeNode(data);
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();

            cout << "Enter left child of " << front->data << " = ";
            cin >> leftData;
            cout << "Enter right child of " << front->data << " = ";
            cin >> rightData;

            if (leftData != -1)
            {
                TreeNode *leftChild = new TreeNode(leftData);
                front->left = leftChild;
                pendingNodes.push(leftChild);
            }
            if (rightData != -1)
            {
                TreeNode *rightChild = new TreeNode(rightData);
                front->right = rightChild;
                pendingNodes.push(rightChild);
            }
        }

        cout << endl;
        return root;
    }

    // Print in level order
    static void printLevelOrder(TreeNode const *root)
    {
        if (root == NULL)
            return;

        queue<TreeNode const *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode const *front = pendingNodes.front();
            pendingNodes.pop();

            cout << front->data << ": ";

            if (front->left != NULL)
            {
                cout << "L -> " << front->left->data;
                pendingNodes.push(front->left);
                if (front->right != NULL)
                    cout << ", ";
            }
            if (front->right != NULL)
            {
                cout << "R -> " << front->right->data;
                pendingNodes.push(front->right);
            }
            cout << endl;
        }
    }

    // Counting total number of nodes
    static int countNodes(TreeNode const *root)
    {
        if (root == NULL)
            return 0;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    // Height of tree
    static int height(TreeNode const *root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    // Depth of node
    static int depth(TreeNode const *root, T data)
    {
        if (root == NULL)
            return -1;

        if (root->data == data)
            return 0;

        int leftDP = depth(root->left, data);
        if (leftDP >= 0)
            return 1 + leftDP;

        int rightDP = depth(root->right, data);
        if (rightDP >= 0)
            return 1 + rightDP;

        return -1;
    }

    // Count leaf nodes
    static int countLeaf(TreeNode const *root)
    {
        if (root == NULL)
            return 0;

        if (root->left == NULL && root->right == NULL)
            return 1;

        return countLeaf(root->left) + countLeaf(root->right);
    }

    // Inorder Traversal
    static void inorderTraversal(TreeNode const *root)
    {
        if (root == NULL)
            return;

        static TreeNode const *mainRoot = root;

        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);

        if (root == mainRoot)
            cout << endl;
    }

    // Preorder Traversal
    static void preorderTraversal(TreeNode const *root)
    {
        if (root == NULL)
            return;

        static TreeNode const *mainRoot = root;

        cout << root->data << " ";
        preorderTraversal(root->left);
        preorderTraversal(root->right);

        if (root == mainRoot)
            cout << endl;
    }

    // Postorder Traversal
    static void postorderTraversal(TreeNode const *root)
    {
        if (root == NULL)
            return;

        static TreeNode const *mainRoot = root;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        cout << root->data << " ";

        if (root == mainRoot)
            cout << endl;
    }

    // Find diameter of binary tree
    static int diameter(TreeNode const *root)
    {
        if (root == NULL)
            return 0;

        int option1 = height(root->left) + height(root->right);
        int option2 = diameter(root->left);
        int option3 = diameter(root->right);

        return max(option1, max(option2, option3));
    }

    // Find diameter by better approach
    static int diameterBetter(TreeNode const *root)
    {
        return diameterBetterHelp(root).second;
    }

    // Construct tree from inorder and preorder traversal
    static TreeNode *constructTreePreIn(int const *in, int const *pre, int size)
    {
        return constructTreePreInHelp(in, pre, 0, size - 1, 0, size - 1);
    }

    // Construct tree from inorder and postorder traversal
    static TreeNode *constructTreePostIn(int const *in, int const *post, int size)
    {
        return constructTreePostInHelp(in, post, 0, size - 1, 0, size - 1);
    }

    // Destroy Tree
    static void destroy(TreeNode *root)
    {
        if (root == NULL)
            return;

        destroy(root->left);
        destroy(root->right);
        delete root;
    }
};