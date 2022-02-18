#include <bits/stdc++.h>
using namespace std;

class Triplet
{
public:
    int minimum, maximum;
    bool isBST;

    Triplet(int minimum, int maximum, bool isBST) : minimum(minimum), maximum(maximum), isBST(isBST) {}
};

class BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;

    static Triplet *checkBST2Help(BSTNode const *root)
    {
        if (root == NULL)
        {
            Triplet *tmp = new Triplet(INT_MAX, INT_MIN, true);
            return tmp;
        }

        Triplet *leftData = checkBST2Help(root->left);
        Triplet *rightData = checkBST2Help(root->right);

        bool isBST = (root->data > leftData->maximum && root->data < rightData->minimum && leftData->isBST && rightData->isBST);
        Triplet *tmp = new Triplet(min(root->data, min(leftData->minimum, rightData->minimum)), max(root->data, max(leftData->maximum, rightData->maximum)), isBST);

        delete leftData;
        delete rightData;

        return tmp;
    }

    static bool checkBST3Help(BSTNode const *root, int minRange, int maxRange)
    {
        if (root == NULL)
            return true;

        if (root->data > maxRange || root->data < minRange)
            return false;

        return checkBST3Help(root->left, minRange, root->data - 1) && checkBST3Help(root->right, root->data + 1, maxRange);
    }

public:
    // Constructor
    BSTNode(int data) : data(data), left(NULL), right(NULL) {}
    BSTNode(int data, BSTNode *left, BSTNode *right) : data(data), left(left), right(right) {}

    // Print in level order
    static void printLevelOrder(BSTNode const *root)
    {
        if (root == NULL)
            return;

        queue<BSTNode const *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            BSTNode const *front = pendingNodes.front();
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

    // Search for a node
    static bool hasNode(BSTNode const *root, int data)
    {
        if (root == NULL)
            return false;

        if (root->data == data)
            return true;
        else if (root->data < data)
            return hasNode(root->right, data);
        else
            return hasNode(root->left, data);
    }

    // Minimum Element
    static int minimum(BSTNode const *root)
    {
        if (root == NULL)
            return INT_MAX;

        return min(root->data, min(minimum(root->left), minimum(root->right)));
    }

    // Maximum Element
    static int maximum(BSTNode const *root)
    {
        if (root == NULL)
            return INT_MIN;

        return max(root->data, max(maximum(root->left), maximum(root->right)));
    }

    // Checking for bst conditions - O(n.h)
    static bool checkBST1(BSTNode const *root)
    {
        if (root == NULL)
            return true;

        int maxLeft = maximum(root->left);
        int minRight = minimum(root->right);

        return (root->data > maxLeft && root->data < minRight && checkBST1(root->left) && checkBST1(root->right));
    }

    // Checking for bst conditions - O(n)
    static bool checkBST2(BSTNode const *root)
    {
        Triplet *tmp = checkBST2Help(root);
        bool isBST = tmp->isBST;
        delete tmp;
        return isBST;
    }

    // Checking for bst conditions - O(n) // Top to bottom
    static bool checkBST3(BSTNode const *root)
    {
        return checkBST3Help(root, INT_MIN, INT_MAX);
    }

    // Construct BST by sorted array
    static BSTNode *constructBST(int const *arr, int start, int end)
    {
        if (start > end)
            return NULL;

        int mid = start + (end - start) / 2;
        BSTNode *root = new BSTNode(arr[mid], constructBST(arr, start, mid - 1), constructBST(arr, mid + 1, start));
        return root;
    }

    // Inorder Traversal
    static void inorderTraversal(BSTNode const *root)
    {
        if (root == NULL)
            return;

        static BSTNode const *mainRoot = root;

        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);

        if (root == mainRoot)
            cout << endl;
    }

    // Inserting data
    static BSTNode *insert(BSTNode *root, int data)
    {
        if (root == NULL)
        {
            BSTNode *newNode = new BSTNode(data);
            return newNode;
        }

        if (data < root->data)
            root->left = insert(root->left, data);
        else if (data > root->data)
            root->right = insert(root->right, data);

        return root;
    }

    // Deleting data
    static BSTNode *remove(BSTNode *root, int data)
    {
        if (root == NULL)
            return root;

        if (data < root->data)
            root->left = remove(root->left, data);
        else if (data > root->data)
            root->right = remove(root->right, data);
        else
        {
            BSTNode *leftNode = root->left;
            BSTNode *rightNode = root->right;

            delete root;

            if (leftNode == NULL)
                return rightNode;
            if (rightNode == NULL)
                return leftNode;

            BSTNode *tmp = rightNode;
            while (tmp->left != NULL)
                tmp = tmp->left;

            BSTNode *newNode = new BSTNode(tmp->data);
            newNode->left = leftNode;
            newNode->right = remove(rightNode, tmp->data);
            return newNode;
        }

        return root;
    }

    // Destroy Tree
    static void destroy(BSTNode *root)
    {
        if (root == NULL)
            return;

        destroy(root->left);
        destroy(root->right);
        delete root;
    }
};