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
        this->data = 0;
        this->next = NULL;
    }

    static void print(Node<T> const *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    static void destroy(Node<T> *head)
    {
        if (head == NULL)
            return;

        destroy(head->next);
        delete head;
    }
};

class Combine
{
public:
    int minimum, maximum, height;
    bool isBST;

    Combine(int minimum, int maximum, int height, bool isBST) : minimum(minimum), maximum(maximum), height(height), isBST(isBST) {}
};

class BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;

public:
    // Constructor
    BSTNode(int data) : data(data), left(NULL), right(NULL) {}
    BSTNode(int data, BSTNode *left, BSTNode *right) : data(data), left(left), right(right) {}

    // Take input in level order
    static BSTNode *takeInputLevelOrder()
    {
        int data, leftData, rightData;

        cin >> data;

        if (data == -1)
            return NULL;

        BSTNode *root = new BSTNode(data);
        queue<BSTNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            BSTNode *front = pendingNodes.front();
            pendingNodes.pop();

            cin >> leftData >> rightData;

            if (leftData != -1)
            {
                BSTNode *leftChild = new BSTNode(leftData);
                front->left = leftChild;
                pendingNodes.push(leftChild);
            }
            if (rightData != -1)
            {
                BSTNode *rightChild = new BSTNode(rightData);
                front->right = rightChild;
                pendingNodes.push(rightChild);
            }
        }

        return root;
    }

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

    // Destroy Tree
    static void destroy(BSTNode *root)
    {
        if (root == NULL)
            return;

        destroy(root->left);
        destroy(root->right);
        delete root;
    }

    // Functions
    static void printInRange(BSTNode const *, int, int);
    static pair<Node<int> *, Node<int> *> *constructByLLHelp(BSTNode const *);
    static Node<int> *constructByLL(BSTNode const *);
    static void pathToNode(BSTNode const *, int);
    static int lca(BSTNode const *, int, int);
    static Combine largstBSTHelp(BSTNode const *);
    static int largstBST(BSTNode const *);
    static void replaceLarger(BSTNode *, int);
    static void pairsum(BSTNode const *, int);
};