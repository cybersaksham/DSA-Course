/*
                    7
            11<-----|----->2
        5<--|              |-->9
-------------------------------------------------------------
|                        l,7,r                              |
|               l,11,r<--|   |-->l,2,r                      |
|       l,5,r<--|    |           |   |-->l,9,r              |
|                   NULL        NULL                        |
|  All left & right pointers of leaf nodes point to NULL    |
-------------------------------------------------------------
*/

/*
Traversal in Binary Tree:

1. Pre-Order:
    Root --> Left Subtree --> Right Subtree
    7[L][R]
    7[11[L][R]][2[L][R]]
    7[11,5,NULL][2,NULL,9]
    7,11,5,NULL,2,NULL,9

2. Post-Order:
    Left Subtree --> Right Subtree --> Root
    [L][R]7
    [[L][R]11][[L][R]2]7
    [5,NULL,11][NULL,9,2]7
    5,NULL,11,NULL,9,2,7

3. In-Order:
    Left Subtree --> Root --> Right Subtree
    [L]7[R]
    [[L]11[R]]7[[L]2[R]]
    [5,11,NULL]7[NULL,2,9]
    5,11,NULL,7,NULL,2,9
*/

/*
Traversal Tricks:

1. Pre-Order    Draw a breaker left to each node
2. Post-Order   Draw a breaker right to each node
3. In-Order     Draw a breaker below of each node

Now start from topmost node & traverse whole binary tree from left arms.
When left arms get over turn around & continue.
Whenever you cross a breaker write down value of associated node.
See below figure for more understanding:

|            /--7
|           / / /\\
|          --11/ --2
|          / //   \\
|         --5/    --9
|          --
|          7 11 5 2 9

Above is for pre-order same can be done with others.
Reference: https://www.youtube.com/watch?v=IqVCDZlciDU&list=PLu0W_9lII9ahIappRPN0MCAgtOu3lQjQi&index=70
*/

/*
Time Complexities (Node)
1. preOrderTraversal()      O(n)
2. postOrderTraversal()     O(n)
3. inOrderTraversal()       O(n)
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

    void preOrderTraversal()
    {
        if (this != NULL)
        {
            cout << this->data << " ";
            this->left->preOrderTraversal();
            this->right->preOrderTraversal();
        }
    }

    void postOrderTraversal()
    {
        if (this != NULL)
        {
            this->left->postOrderTraversal();
            this->right->postOrderTraversal();
            cout << this->data << " ";
        }
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
    n0->setData(7, n1, n2);
    n1->setData(11, n3, NULL);
    n2->setData(2, NULL, n4);
    n3->setData(5, NULL, NULL);
    n4->setData(9, NULL, NULL);

    // Traversing
    n0->preOrderTraversal();
    cout << endl;
    n0->postOrderTraversal();
    cout << endl;
    n0->inOrderTraversal();

    return 0;
}