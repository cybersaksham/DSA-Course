/*
You have been given a singly linked list of integers along with two integers, 'i,' and 'j.' Swap the nodes that are present at the 'i-th'  and 'j-th' positions.
Note :
Remember, the nodes themselves must be swapped and not the datas.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'i,' and 'j,' respectively. A single space will separate them.

Remember/consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node::swapNodes(Node *head, int i, int j)
{
    int len = Node::length(head);

    if ((i < 0 || i >= len) || (j < 0 || j >= len) || i == j)
        return head;

    if (min(i, j) == 0)
    {
        if (j == 1)
        {
            Node *b = head->next;
            head->next = b->next;
            b->next = head;
            return b;
        }

        int p = 0;
        int q = max(i, j);

        Node *tmp2 = head;
        for (int k = 1; k < q; k++)
            tmp2 = tmp2->next;

        Node *b = tmp2->next;
        tmp2->next = b->next;
        b->next = head->next;
        head->next = tmp2->next;
        tmp2->next = head;

        return b;
    }

    Node *tmp1 = head;
    for (int k = 1; k < i; k++)
        tmp1 = tmp1->next;

    Node *tmp2 = head;
    for (int k = 1; k < j; k++)
        tmp2 = tmp2->next;

    Node *a = tmp1->next;
    Node *b = tmp2->next;

    tmp2->next = a;
    tmp1->next = a->next;
    a->next = b->next;
    b->next = tmp1->next;
    tmp1->next = b;

    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int i, j;

        Node *head = Node::input();
        cin >> i >> j;

        head = Node::swapNodes(head, i, j);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}