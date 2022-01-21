/*
You have been given a singly linked list of integers where the elements are sorted in ascending order. Write a function that removes the consecutive duplicate values such that the given list only contains unique elements and returns the head to the updated list.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first and the only line of each test case or query contains the elements(in ascending order) of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.
*/

#include <iostream>
#include <map>
#include "./Node.cpp"
using namespace std;

void Node::removeDuplicates(Node *head)
{
    map<int, int> m;
    Node *tmp = head;
    Node *prev = NULL;
    while (tmp != NULL)
    {
        if (m[tmp->data] == 0)
        {
            m[tmp->data]++;
        }
        else
        {
            prev->next = tmp->next;
            delete tmp;
            tmp = prev;
        }

        prev = tmp;
        tmp = tmp->next;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = Node::input();

        Node::removeDuplicates(head);
        Node::print(head);

        Node::destroy(head);
    }

    return 0;
}