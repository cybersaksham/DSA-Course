/*
Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
*/

#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

template <typename T>
Node<TreeNode<T> const *> **TreeNode<T>::levelList(TreeNode<T> const *root)
{
    const int ht = TreeNode::height(root);
    cout << ht << endl;

    Node<TreeNode<T> const *> **heads = new Node<TreeNode<T> const *> *[ht];
    if (root == NULL)
        return heads;

    queue<TreeNode<T> const *> pendingNodes;
    pendingNodes.push(root);
    pendingNodes.push(NULL);

    Node<TreeNode const *> *tmpHead = new Node<TreeNode const *>;
    Node<TreeNode const *> *tmpTail = new Node<TreeNode const *>;
    Node<TreeNode const *> *prevTail = new Node<TreeNode const *>;

    int i = 0;
    while (!pendingNodes.empty())
    {
        TreeNode const *node = pendingNodes.front();
        pendingNodes.pop();

        if (tmpHead == NULL)
        {
            Node<TreeNode const *> *tmp = new Node<TreeNode const *>;
            tmp->data = node;
            tmpHead = tmp;
            tmpTail = tmp;
        }
        else if (tmpHead->data == NULL)
        {
            tmpHead->data = node;
            tmpTail->data = node;
        }
        else if (node != NULL)
        {
            Node<TreeNode const *> *tmp = new Node<TreeNode const *>;
            tmp->data = node;
            tmpTail->next = tmp;
            prevTail = tmpTail;
            tmpTail = tmp;
        }

        if (node == NULL)
        {
            Node<TreeNode const *> *tmp = new Node<TreeNode const *>;
            tmp->data = tmpHead->data;
            tmp->next = tmpHead->next;
            Node<TreeNode const *> *tmp2 = new Node<TreeNode const *>;
            tmp2->data = tmpTail->data;
            tmp2->next = tmpTail->next;
            prevTail->next = tmpTail;
            heads[i++] = tmp;
            tmpHead = NULL;
            tmpTail = NULL;
            if (!pendingNodes.empty())
                pendingNodes.push(NULL);
            continue;
        }

        if (node->left)
            pendingNodes.push(node->left);
        if (node->right)
            pendingNodes.push(node->right);
    }

    return heads;
}

int main()
{
    TreeNode<int> *root = TreeNode<int>::takeInputLevelOrder();
    Node<TreeNode<int> const *> **heads = TreeNode<int>::levelList(root);

    const int ht = TreeNode<int>::height(root);
    for (int i = 0; i < ht; i++)
    {
        Node<TreeNode<int> const *> *tmp = heads[i];
        while (tmp != NULL)
        {
            cout << tmp->data->data << " ";
            tmp = tmp->next;
        }
        cout << endl;
        Node<TreeNode<int> const *>::destroy(heads[i]);
    }

    TreeNode<int>::destroy(root);
    delete[] heads;

    return 0;
}