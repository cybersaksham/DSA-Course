/*
[a1, n1] --> [a2, n2] --> ...... --> [ai, ni]
    ^                                   |
    -------------------------------------
*/

/*
Time Complexities (Node)
1. setData()           Setting data            O(1)
2. traversal()         Printing data           O(n)
3. push_before()       Inserting before node   O(n)
4. push_after()        Inserting after node    O(1)
5. pop_node()          Deleting a node         O(n)
*/

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    void setData(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    void traversal()
    {
        Node *ptr = this;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != this);
        cout << endl;
    }

    void push_before(int element)
    {
        Node *newNode = new Node[sizeof(Node)];
        Node *ptr = this;
        newNode->data = element;
        while (ptr->next != this)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void push_after(int element)
    {
        Node *newNode = new Node[sizeof(Node)];
        Node *ptr = this;
        newNode->data = element;
        newNode->next = ptr->next;
        ptr->next = newNode;
    }

    void pop_node()
    {
        Node *ptr = this;
        while (ptr->next != this)
        {
            ptr = ptr->next;
        }
        ptr->next = this->next;
        delete this;
    }
};

int main()
{
    Node *head = new Node[sizeof(Node)];
    Node *second = new Node[sizeof(Node)];
    Node *third = new Node[sizeof(Node)];

    // head
    head->setData(7, second);

    // second
    second->setData(-5, third);

    // third
    third->setData(15, head);

    // Traversing
    head->traversal();

    // Inserting
    second->push_before(25);
    head->push_after(100);
    head->traversal();

    // Deleting
    second->pop_node();
    head->traversal();

    return 0;
}