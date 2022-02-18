/*
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.

Output Format:
The first and only line of output prints the elements of sorted linked list.
*/

#include <iostream>
#include <list>
#include "BSTNode.h"
using namespace std;

pair<Node<int> *, Node<int> *> *BSTNode::constructByLLHelp(BSTNode const *root)
{
    if (root == NULL)
    {
        pair<Node<int> *, Node<int> *> *newPair = new pair<Node<int> *, Node<int> *>;
        newPair->first = NULL;
        newPair->second = NULL;

        return newPair;
    }

    pair<Node<int> *, Node<int> *> *leftList = constructByLLHelp(root->left);
    pair<Node<int> *, Node<int> *> *rightList = constructByLLHelp(root->right);

    Node<int> *newNode = new Node<int>;
    newNode->data = root->data;
    newNode->next = rightList->first;

    if (leftList->first != NULL)
        leftList->second->next = newNode;
    else
        leftList->first = newNode;

    if (rightList->first != NULL)
        leftList->second = rightList->second;
    else
        leftList->second = newNode;

    delete rightList;
    return leftList;
}

Node<int> *BSTNode::constructByLL(BSTNode const *root)
{
    pair<Node<int> *, Node<int> *> *newPair = constructByLLHelp(root);
    Node<int> *head = newPair->first;

    delete newPair;
    return head;
}

int main()
{
    BSTNode *root = BSTNode::takeInputLevelOrder();

    Node<int> *head = BSTNode::constructByLL(root);
    Node<int>::print(head);

    Node<int>::destroy(head);
    BSTNode::destroy(root);

    return 0;
}