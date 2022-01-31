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

    // Take input in level order
    static TreeNode *takeInputLevelOrder()
    {
        T data;
        int n;

        cin >> data;

        TreeNode *root = new TreeNode(data);
        queue<TreeNode *> pendingNodes;
        pendingNodes.push(root);

        while (!pendingNodes.empty())
        {
            TreeNode *front = pendingNodes.front();
            pendingNodes.pop();

            cin >> n;

            for (int i = 0; i < n; i++)
            {
                cin >> data;

                TreeNode *newNode = new TreeNode(data);
                pendingNodes.push(newNode);
                front->children.push_back(newNode);
            }
        }

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

    // Destroy Tree
    static void destroy(TreeNode *root)
    {
        if (root == NULL)
            return;

        for (int i = 0; i < root->children.size(); i++)
            destroy(root->children[i]);
        delete root;
    }

    // Functions
    static bool isPresent(TreeNode const *, T);
    static bool areIdentical(TreeNode const *, TreeNode const *);
    static void replaceWithDepth(TreeNode *);
};