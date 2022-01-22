/*
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains a single integer depicting the value of 'k'.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node ::reverseEachKNodes(Node *head, int k)
{
    if (k <= 1)
        return head;

    Node *start = NULL;
    Node *end = NULL;
    Node *prevEnd = NULL;
    Node *newHead = NULL;

    Node *tmp = head;
    while (tmp != NULL)
    {
        for (int i = 0; i < k; i++)
        {
            if (tmp == NULL)
                break;

            Node *tmp2 = tmp->next;
            tmp->next = start;
            start = tmp;
            tmp = tmp2;
            if (end == NULL)
                end = start;
        }
        if (newHead == NULL)
            newHead = start;
        if (prevEnd != NULL)
            prevEnd->next = start;
        end->next = tmp;
        prevEnd = end;
        start = end;
        end = NULL;
    }

    return newHead;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int k;

        Node *head = Node::input();
        cin >> k;

        head = Node::reverseEachKNodes(head, k);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}