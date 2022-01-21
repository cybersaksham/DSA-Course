/*
You have been given a singly linked list of integers. Write a function that returns the index/position of an integer data denoted by 'N' (if it exists). Return -1 otherwise.

Note :
Assume that the Indexing for the singly linked list always starts from 0.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line contains the integer value 'N'. It denotes the data to be searched in the given singly linked list.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

int Node::getIndex(Node *head, int data)
{
    Node *tmp = head;
    int count = 0;
    while (tmp != NULL && tmp->data != data)
    {
        count++;
        tmp = tmp->next;
    }

    if (tmp == NULL)
        return -1;
    else
        return count;
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

        cout << Node::getIndex(head, data) << endl;

        Node::destroy(head);
    }

    return 0;
}