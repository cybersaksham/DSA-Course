/*
Given a singly linked list of integers and an integer n, find and return the index for the first occurrence of 'n'  in the linked list. -1 otherwise.
Follow a recursive approach to solve this.
Note :
Assume that the Indexing for the linked list always starts from 0.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'n'.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

int Node::getIndexRecursive(Node *head, int data)
{
    static int count = 0;

    if (head == NULL)
        return -1;

    if (head->data == data)
        return count;

    count++;
    return Node::getIndexRecursive(head->next, data);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int data;

        Node *head = Node::input();
        cin >> data;

        cout << Node::getIndexRecursive(head, data) << endl;

        Node::destroy(head);
    }

    return 0;
}