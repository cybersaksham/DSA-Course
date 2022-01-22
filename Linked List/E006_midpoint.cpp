/*
For a given singly linked list of integers, find and return the node present at the middle of the list.
Note :
If the length of the singly linked list is even, then return the first middle node.

Example: Consider, 10 -> 20 -> 30 -> 40 is the given list, then the nodes present at the middle with respective data values are, 20 and 30. We return the first node with data 20.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

int Node::midpoint(Node *head)
{
    int length = Node::length(head);
    int mid = (length - 1) / 2;

    if (length <= 0)
        return -1;

    Node *tmp = head;
    while (mid--)
        tmp = tmp->next;

    return tmp->data;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = Node::input();

        cout << Node::midpoint(head) << endl;

        Node::destroy(head);
    }

    return 0;
}