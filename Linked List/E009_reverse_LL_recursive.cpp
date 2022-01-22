/*
Given a singly linked list of integers, reverse it using recursion and return the head to the modified list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node::reverseRecursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *reversedHead = Node::reverseRecursive(head->next);
    head->next->next = head;
    head->next = NULL;

    return reversedHead;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = Node::input();

        head = Node::reverseRecursive(head);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}