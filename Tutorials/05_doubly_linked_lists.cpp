/*
NULL <-- [a1, n1, p1] <--> [a2, n2, p2] <--> ...... <--> [ai, ni, pi] --> NULL
*/

/*
Time Complexities (Node)
1. setData()           Setting data            O(1)
2. traversal()         Printing data           O(n)
*/

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;
    Node *prev;

public:
    void setData(Node *prev, int data, Node *next)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }

    void traversal(int reversed)
    {
        Node *ptr = this;
        if (!reversed)
        {
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout << endl;
        }
        else
        {
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                ptr = ptr->prev;
            }
            cout << endl;
        }
    }
};

int main()
{
    Node *head = new Node[sizeof(Node)];
    Node *second = new Node[sizeof(Node)];
    Node *third = new Node[sizeof(Node)];
    Node *fourth = new Node[sizeof(Node)];

    // Assigning Data
    head->setData(NULL, 1, second);
    second->setData(head, 2, third);
    third->setData(second, 3, fourth);
    fourth->setData(third, 4, NULL);

    // Traversing
    head->traversal(0);
    head->traversal(1);

    return 0;
}