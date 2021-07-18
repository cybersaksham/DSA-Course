/*
A Binary Tree is Binary Search Tree (BST) if:

1. All nodes of left subtree are lesser than root node.
2. All nodes of right subtree are greater than root node.
3. Left & Right subtrees are also BST.
4. There are no duplicate nodes.
5. In-order traversal is always an ascending sorted array.
*/

/*
Time Complexities (Node)
1. isBST()                  Checking for BST            O(n)
2. searchBSTRecursive()     Searching element in BST    O(h)
3. searchBSTIterative()     Searching element in BST    O(h)
4. insertBST()              Inserting element in BST    O(h)
5. deleteBST()              Deleting element in BST     O(h)
where h is height of tree
*/

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *left;
    Node *right;

public:
    void setData(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

    void inOrderTraversal()
    {
        if (this != NULL)
        {
            this->left->inOrderTraversal();
            cout << this->data << " ";
            this->right->inOrderTraversal();
        }
    }

    int isBST()
    {
        if (this == NULL)
            return 1;
        static Node *prev = NULL;
        if (!this->left->isBST())
            return 0;
        if (prev != NULL && this->data <= prev->data)
            return 0;
        prev = this;
        return this->right->isBST();
    }

    Node *searchBSTRecursive(int element)
    {
        if (this == NULL || this->data == element)
            return this;
        else if (this->data > element)
            return this->left->searchBSTRecursive(element);
        else
            return this->right->searchBSTRecursive(element);
    }

    Node *searchBSTIterative(int element)
    {
        Node *ptr = this;
        while (ptr != NULL && ptr->data != element)
        {
            if (ptr->data > element)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        return ptr;
    }

    Node *insertBST(int element)
    {
        Node *ptr = this;
        Node *prev = NULL;

        while (ptr != NULL)
        {
            prev = ptr;
            if (element == ptr->data)
                return ptr;
            else if (element < ptr->data)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }

        Node *newNode = new Node[sizeof(Node)];
        newNode->setData(element, NULL, NULL);

        if (element < prev->data)
            prev->left = newNode;
        else
            prev->right = newNode;
        return newNode;
    }

    Node *deleteBST(int element)
    {
        Node *iPre;
        if (this == NULL)
            return NULL;
        if (this->left == NULL && this->right == NULL)
        {
            delete this;
            return NULL;
        }

        if (element < this->data)
            this->left = this->left->deleteBST(element);
        else if (element > this->data)
            this->right = this->right->deleteBST(element);
        else
        {
            Node *ptr = this;
            if (ptr->left == NULL)
            {
                iPre = ptr->right;
                this->data = iPre->data;
                this->right = this->right->deleteBST(iPre->data);
            }
            else
            {
                ptr = ptr->left;
                while (ptr->right != NULL)
                {
                    ptr = ptr->right;
                }
                iPre = ptr;
                this->data = iPre->data;
                this->left = this->left->deleteBST(iPre->data);
            }
        }
        return this;
    }
};

int main()
{
    // Making Nodes
    Node *n0 = new Node[sizeof(Node)];
    Node *n1 = new Node[sizeof(Node)];
    Node *n2 = new Node[sizeof(Node)];
    Node *n3 = new Node[sizeof(Node)];
    Node *n4 = new Node[sizeof(Node)];

    // Linking Data
    n0->setData(5, n1, n2);
    n1->setData(3, n3, n4);
    n2->setData(6, NULL, NULL);
    n3->setData(1, NULL, NULL);
    n4->setData(4, NULL, NULL);

    // Checking for BST
    if (n0->isBST())
        cout << "Tree is BST" << endl;
    else
        cout << "Tree is not BST" << endl;

    // Searching
    cout << "Recursive" << endl;
    for (int i = -1; i < 4; i++)
    {
        if (n0->searchBSTRecursive(i) == NULL)
            cout << i << " is not present in BST" << endl;
        else
            cout << i << " is present in BST" << endl;
    }
    cout << "Iterative" << endl;
    for (int i = -1; i < 4; i++)
    {
        if (n0->searchBSTIterative(i) == NULL)
            cout << i << " is not present in BST" << endl;
        else
            cout << i << " is present in BST" << endl;
    }

    // Inserting
    if (n0->insertBST(2) != NULL)
        cout << 2 << " inserted." << endl;
    else
        cout << 2 << " couldn't inserted." << endl;
    n0->inOrderTraversal();
    cout << endl;

    // Deleting
    n0->deleteBST(6);
    n0->inOrderTraversal();
    cout << endl;

    return 0;
}