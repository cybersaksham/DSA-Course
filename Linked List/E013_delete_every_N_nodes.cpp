/*
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node::deleteEveryNNodes(Node *head, int M, int N)
{
    if (N < 0 || M < 0)
        return head;

    if (M == 0)
    {
        if (N > 0)
        {
            Node::destroy(head);
            return NULL;
        }
        else
            return head;
    }

    if (N == 0)
        return head;

    Node *tmp = head;
    while (tmp != NULL)
    {
        for (int i = 1; i < M; i++)
        {
            if (tmp == NULL)
                break;
            tmp = tmp->next;
        }

        if (tmp == NULL)
            break;

        for (int i = 0; i < N; i++)
        {
            if (tmp == NULL || tmp->next == NULL)
                break;
            Node *tmp2 = tmp->next->next;
            delete tmp->next;
            tmp->next = tmp2;
        }

        tmp = tmp->next;
    }

    return head;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int M, N;

        Node *head = Node::input();
        cin >> M >> N;

        head = Node::deleteEveryNNodes(head, M, N);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}