/*
You have been given a singly linked list of integers along with an integer 'N'. Write a function to append the last 'N' nodes towards the front of the singly linked list and returns the new head to the list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the integer value 'N'. It denotes the number of nodes to be moved from last to the front of the singly linked list.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node::appendLastNToFirst(Node *head, int N)
{
    int length = Node::length(head);
    int i = length - N;

    Node *tmp = head;
    while (tmp != NULL && --i)
    {
        tmp = tmp->next;
    }

    if (tmp == NULL)
        return head;

    Node *tail = tmp;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->next = head;
    Node *a = tmp->next;
    tmp->next = NULL;
    return a;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int N;

        Node *head = Node::input();
        cin >> N;

        head = Node::appendLastNToFirst(head, N);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}