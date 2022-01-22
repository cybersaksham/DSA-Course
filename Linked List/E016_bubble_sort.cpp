/*
Given a singly linked list of integers, sort it using 'Bubble Sort.'

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node::bubbleSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *tmp = head;
    Node *newHead = head;
    Node *sorted = NULL;

    while (tmp != sorted)
    {
        int count = 0;
        Node *prev = NULL;
        Node *tmp2 = tmp;
        while (tmp2->next != sorted)
        {
            Node *tmp3 = tmp2->next;
            if (tmp3->data < tmp2->data)
            {
                tmp2->next = tmp3->next;
                tmp3->next = tmp2;
                if (prev != NULL)
                    prev->next = tmp3;
                else
                    newHead = tmp3;
                prev = tmp3;
                count++;
            }
            else
            {
                prev = tmp2;
                tmp2 = tmp2->next;
            }
        }
        if (count == 0)
            break;
        sorted = tmp2;
        tmp = newHead;
    }

    return newHead;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = Node::input();

        head = Node::bubbleSort(head);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}