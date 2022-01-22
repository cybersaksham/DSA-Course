/*
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) and return the new head to the list.
Note :
Try solving this in O(1) auxiliary space.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the first sorted singly linked list separated by a single space.

The second line of the input contains the elements of the second sorted singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node::merge(Node *head1, Node *head2)
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

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head1 = Node::input();
        Node *head2 = Node::input();

        head1 = Node::merge(head1, head2);
        Node::print(head1);

        Node::destroy(head1);
    }

    return 0;
}