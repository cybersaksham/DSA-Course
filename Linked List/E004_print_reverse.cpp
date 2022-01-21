/*
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
To explain it further, you need to start printing the data from the tail and move towards the head of the list, printing the head data at the end.

Note :
You can’t change any of the pointers in the linked list, just print it in the reverse order.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Constraints :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

void Node::printReverseHelp(Node *head)
{
    if (head == NULL)
        return;

    Node::printReverseHelp(head->next);
    cout << head->data << " ";
}

void Node::printReverse(Node *head)
{
    Node::printReverseHelp(head);
    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = Node::input();

        Node::printReverse(head);

        Node::destroy(head);
    }

    return 0;
}