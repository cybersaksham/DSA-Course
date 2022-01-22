/*
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed after the odd numbers. The relative order of the odd and even terms should remain unchanged.

Input format:
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

Node *Node::evenAfterOdd(Node *head)
{
    Node *evenHead = new Node(0);
    Node *evenTail = evenHead;
    Node *oddHead = new Node(1);
    Node *oddTail = oddHead;

    Node *tmp = head;
    while (tmp != NULL)
    {
        if (tmp->data % 2 == 0)
        {
            evenTail->next = tmp;
            evenTail = tmp;
        }
        else
        {
            oddTail->next = tmp;
            oddTail = tmp;
        }
        tmp = tmp->next;
    }
    evenTail->next = NULL;
    oddTail->next = NULL;

    if (oddHead->next == NULL)
    {
        Node *tmp1 = evenHead->next;
        delete oddHead;
        delete evenHead;
        return tmp1;
    }
    else
    {
        Node *tmp1 = evenHead->next;
        Node *tmp2 = oddHead->next;
        delete oddHead;
        delete evenHead;
        oddTail->next = tmp1;
        return tmp2;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = Node::input();

        head = Node::evenAfterOdd(head);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}