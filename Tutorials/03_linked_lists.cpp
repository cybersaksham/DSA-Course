/*
[a1, n1] --> [a2, n2] --> ...... --> [ai, ni] --> NULL
*/

/*
Time Complexities (Node)
1.  setData()           Setting data            O(1)
2.  traversal()         Printing data           O(n)
3.  push_front()        Inserting at front      O(1)
4.  push_back()         Inserting at last       O(n)
5.  push()              Inserting at index      O(n)
6.  push_after()        Inserting after node    O(1)
7.  push_before()       Inserting before node   O(n)
8.  pop_front()         Deleting from front     O(1)
9.  pop_back()          Deleting from last      O(n)
10. pop()               Deleting at index       O(n)
11. pop_node()          Deleting a node         O(n)
12. pop_val()           Deleting a value        O(n)
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
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    Node *push_front(int element)
    {
        Node *newNode = new Node[sizeof(Node)];
        newNode->setData(element, this);
        return newNode;
    }

    Node *push_back(int element)
    {
        Node *ptr = this;
        Node *newNode = new Node[sizeof(Node)];
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        newNode->setData(element, NULL);
        ptr->next = newNode;
        return this;
    }

    Node *push(int index, int element)
    {
        Node *ptr = this;
        Node *newNode = new Node[sizeof(Node)];
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
            if (ptr->next == NULL)
                break;
        }
        newNode->setData(element, ptr->next);
        ptr->next = newNode;
        return this;
    }

    Node *push_after(Node *node, int element)
    {
        Node *newNode = new Node[sizeof(Node)];
        newNode->setData(element, node->next);
        node->next = newNode;
        return this;
    }

    Node *push_before(Node *node, int element)
    {
        Node *ptr = this;
        Node *newNode = new Node[sizeof(Node)];
        while (ptr->next != node)
        {
            ptr = ptr->next;
            if (ptr->next == NULL)
                return this;
        }
        newNode->setData(element, node);
        ptr->next = newNode;
        return this;
    }

    Node *pop_front()
    {
        Node *ptr = this->next;
        delete this;
        return ptr;
    }

    Node *pop_back()
    {
        Node *ptr = this;
        while ((ptr->next)->next != NULL)
        {
            ptr = ptr->next;
        }
        delete ptr->next;
        ptr->next = NULL;
        return this;
    }

    Node *pop(int index)
    {
        Node *ptr = this;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
            if (ptr->next == NULL)
                return this;
        }
        Node *dltPtr = ptr->next;
        ptr->next = dltPtr->next;
        delete dltPtr;
        return this;
    }

    Node *pop_node(Node *node)
    {
        Node *ptr = this;
        while (ptr->next != node)
        {
            ptr = ptr->next;
            if (ptr->next == NULL)
                return this;
        }
        ptr->next = node->next;
        delete node;
        return this;
    }

    Node *pop_val(int val)
    {
        Node *ptr = this;
        while ((ptr->next)->data != val)
        {
            ptr = ptr->next;
            if (ptr->next == NULL)
                return this;
        }
        delete ptr->next;
        ptr->next = (ptr->next)->next;
        return this;
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
    third->setData(15, NULL);

    // Traversing
    head->traversal();

    // Inserting
    head = head->push_front(100);
    head = head->push(2, 20);
    head = head->push_back(-100);
    head = head->push_after(second, -50);
    head = head->push_before(second, -40);
    head->traversal();

    // Deleting
    head = head->pop_front();
    head = head->pop_back();
    head = head->pop(2);
    head = head->pop_node(third);
    head = head->pop_val(20);
    head->traversal();

    return 0;
}