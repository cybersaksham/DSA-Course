#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node()
    {
        this->data = NULL;
        this->next = NULL;
    }

    static void destroy(Node<T> *head)
    {
        if (head == NULL)
            return;

        destroy(head->next);
        delete head;
    }
};

template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode *left;
    TreeNode *right;

    // Constructor
    TreeNode(T data) : data(data), left(NULL), right(NULL) {}
    TreeNode(T data, TreeNode *left, TreeNode *right) : data(data), left(left), right(right) {}

    // Take input in level order
    static TreeNode *takeInputLevelOrder()
    {
        T data, leftData, rightData;

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

            cin >> leftData >> rightData;

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

    // Height of tree
    static int height(TreeNode const *root)
    {
        if (root == NULL)
            return 0;

        return 1 + max(height(root->left), height(root->right));
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

    // Functions
    static bool isPresent(TreeNode const *, T);
    static void mirrorTree(TreeNode *);
    static T getMin(TreeNode const *);
    static T getMax(TreeNode const *);
    static bool checkBalanced(TreeNode const *);
    static TreeNode *removeLeaf(TreeNode *);
    static void printLevels(TreeNode const *);
    static Node<TreeNode<T> const *> **levelList(TreeNode const *);
    static void zigzagLevels(TreeNode const *);
    static void noSiblings(TreeNode const *);
};