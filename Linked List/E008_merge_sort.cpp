/*
Given a singly linked list of integers, sort it using 'Merge Sort.'

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node::mergeTwo(Node *head1, Node *head2)
{
    Node *head = NULL;
    Node *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            if (head == NULL)
            {
                head = tail = head1;
            }
            else
            {
                tail->next = head1;
                tail = tail->next;
            }
            head1 = head1->next;
        }
        else if (head1->data > head2->data)
        {
            if (head == NULL)
            {
                head = tail = head2;
            }
            else
            {
                tail->next = head2;
                tail = tail->next;
            }
            head2 = head2->next;
        }
    }

    if (head1 != NULL)
        tail->next = head1;

    if (head2 != NULL)
        tail->next = head2;

    return head;
}

Node *Node::mergeSort(Node *head)
{
    int length = Node::length(head);
    int mid = (length - 1) / 2;

    if (length <= 1)
        return head;

    Node *head1 = head;
    Node *head2 = head;

    while (mid--)
        head2 = head2->next;

    Node *tmp = head2->next;
    head2->next = NULL;
    head2 = tmp;

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);

    head = Node::mergeTwo(head1, head2);
    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = Node::input();

        head = Node::mergeSort(head);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}