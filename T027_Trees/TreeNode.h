#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
    T data;
    vector<TreeNode *> children;

public:
    // Constructor
    TreeNode(T data) : data(data) {}

    // Take input recursively
    static TreeNode *takeInputRecursive()
    {
        T data;
        int n;

        cout << "Enter data = ";
        cin >> data;

        cout << "Enter number of children = ";
        cin >> n;

        TreeNode *root = new TreeNode(data);

        for (int i = 0; i < n; i++)
            root->children.push_back(takeInputRecursive());

        cout << endl;
        return root;
    }

    // Print Recursively
    static void printRecursively(TreeNode const *root)
    {
        if (root == NULL)
            return;

        cout << root->data << ": ";

        for (int i = 0; i < root->children.size(); i++)
        {
            cout << root->children[i]->data;

            if (i < root->children.size() - 1)
                cout << ", ";
        }
        cout << endl;

        for (int i = 0; i < root->children.size(); i++)
            printRecursively(root->children[i]);
    }

    // Take input in level order
    static TreeNode *takeInputLevelOrder()
    {
        T data;
        int n;

        cout << "Enter data of root = ";
        cin >> data;

        TreeNode *root = new TreeNode(data);
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();

            cout << "Enter number of children of " << front->data << " = ";
            cin >> n;

            for (int i = 0; i < n; i++)
            {
                cout << "Enter data of node " << (i + 1) << " = ";
                cin >> data;

                TreeNode *newNode = new TreeNode(data);
                pendingNodes.push(newNode);
                front->children.push_back(newNode);
            }
        }

        cout << endl;
        return root;
    }

    // Print in level order
    static void printLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return;

        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();

            cout << front->data << ": ";

            for (int i = 0; i < front->children.size(); i++)
            {
                cout << front->children[i]->data;

                if (i < front->children.size() - 1)
                    cout << ", ";

                pendingNodes.push(front->children[i]);
            }
            cout << endl;
        }
    }

    // Counting total number of nodes
    static int countNodes(TreeNode const *root)
    {
        if (root == NULL)
            return 0;

        int count = 1;
        for (int i = 0; i < root->children.size(); i++)
            count += countNodes(root->children[i]);

        return count;
    }

    // Height of tree
    static int height(TreeNode const *root)
    {
        if (root == NULL)
            return 0;

        int ht = 0;
        for (int i = 0; i < root->children.size(); i++)
            ht = max(ht, height(root->children[i]));

        return 1 + ht;
    }

    // Depth of node
    static int depth(TreeNode const *root, T data)
    {
        if (root == NULL)
            return -1;

        if (root->data == data)
            return 0;

        for (int i = 0; i < root->children.size(); i++)
        {
            int dp = depth(root->children[i], data);

            if (dp >= 0)
                return 1 + dp;
        }

        return -1;
    }

    // Count leaf nodes
    static int countLeaf(TreeNode const *root)
    {
        if (root == NULL)
            return 0;

        if (root->children.size() == 0)
            return 1;
        else
        {
            int leaves = 0;
            for (int i = 0; i < root->children.size(); i++)
                leaves += countLeaf(root->children[i]);
            return leaves;
        }
    }

    // Preorder Traversal
    static void preorderTraversal(TreeNode const *root)
    {
        if (root == NULL)
            return;

        static TreeNode const *mainRoot = root;

        cout << root->data << " ";
        for (int i = 0; i < root->children.size(); i++)
            preorderTraversal(root->children[i]);

        if (root == mainRoot)
            cout << endl;
    }

    // Postorder Traversal
    static void postorderTraversal(TreeNode const *root)
    {
        if (root == NULL)
            return;

        static TreeNode const *mainRoot = root;

        for (int i = 0; i < root->children.size(); i++)
            postorderTraversal(root->children[i]);

        cout << root->data << " ";
        if (root == mainRoot)
            cout << endl;
    }

    // Destroy Tree
    static void destroy(TreeNode *root)
    {
        if (root == NULL)
            return;

        for (int i = 0; i < root->children.size(); i++)
            destroy(root->children[i]);
        delete root;
    }
};