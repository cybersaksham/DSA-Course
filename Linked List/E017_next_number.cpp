/*
Given a large number represented in the form of a linked list. Write code to increment the number by 1 in-place(i.e. without using extra space).

Input Constraints:
1 <= Length of Linked List <=10^6.

Input format :
Linked list elements (separated by space and terminated by -1)
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

int Node::nextNumberHelp(Node *head)
{
    if (head == NULL)
        return 1;

    int carry = Node::nextNumberHelp(head->next);

    if (carry == 0)
        return 0;
    else if (carry == 1)
    {
        if (head->data == 9)
        {
            head->data = 0;
            return 1;
        }
        else
        {
            head->data++;
            return 0;
        }
    }

    return carry;
}

Node *Node::nextNumber(Node *head)
{
    int carry = Node::nextNumberHelp(head);

    if (carry == 0)
        return head;

    Node *newNode = new Node(1, head);
    return newNode;
}

int main()
{
    Node *head = Node::input();

    head = Node::nextNumber(head);
    Node::print(head);

    Node::destroy(head);

    return 0;
}