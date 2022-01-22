#include <iostream>
using namespace std;

template <typename T>
class Node
{
    T data;
    Node *prev;
    Node *next;

public:
    // Constructors
    Node(T data) : prev(this), data(data), next(this) {}
    Node(Node *prev, T data) : prev(prev), data(data), next(this) {}
    Node(T data, Node *next) : prev(this), data(data), next(next) {}
    Node(Node *prev, T data, Node *next) : prev(prev), data(data), next(next) {}

    // Getter for prev
    T getPrev() const { return this->prev; }

    // Getter for data
    T getData() const { return this->data; }

    // Getter for next
    Node *getNext() const { return this->next; }

    // Setter for prev
    T setPrev(Node *prev) { this->prev = prev; }

    // Setter for data
    void setData(T data) { this->data = data; }

    // Setter for next
    void setNext(Node *next) { this->next = next; }

    // Print Complete List
    static void print(Node *head)
    {
        Node *tmp = head;
        if (tmp == NULL)
            return;

        do
        {
            cout << tmp->data << " ";
            tmp = tmp->next;
        } while (tmp != head);

        cout << endl;
    }

    // Take input for linked list until user presses enter key
    static Node *input()
    {
        Node *head = NULL;
        Node *tail = NULL;

        T a;

        do
        {
            cin >> a;

            Node *newNode = new Node(tail, a);

            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
        } while ((getchar()) == ' ');

        tail->next = head;
        head->prev = tail;

        return head;
    }

    // Insertion at index i
    static Node *insert(Node *head, int i, T data)
    {
        if (i == 0)
        {
            Node *tmp = head == NULL ? head : head->prev;
            Node *newNode = new Node(tmp, data, head);

            if (tmp != NULL)
            {
                tmp->next = newNode;
                head->prev = newNode;
            }
            else
            {
                newNode->next = newNode;
                newNode->prev = newNode;
            }

            return newNode;
        }

        if (NULL == head)
        {
            throw out_of_range("Index out of range");
        }

        Node *tmp = head;
        while (tmp->next != head && --i)
        {
            tmp = tmp->next;
        }

        if (tmp->next == head && i != 1)
        {
            throw out_of_range("Index out of range");
        }

        Node *newNode = new Node(tmp, data, tmp->next);
        tmp->next->prev = newNode;
        tmp->next = newNode;

        return head;
    }

    // Deletion at index i
    static Node *remove(Node *head, int i)
    {
        if (head == NULL)
        {
            throw out_of_range("Index out of range");
        }

        if (i == 0)
        {
            Node *a = head->next;
            Node *b = head->prev;
            b->next = a;
            a->prev = b;

            Node *tmp = a == head ? NULL : a;
            delete head;
            return tmp;
        }

        Node *tmp = head;
        while (tmp->next != head && --i)
        {
            tmp = tmp->next;
        }

        if (tmp->next == head)
        {
            throw out_of_range("Index out of range");
        }

        Node *a = tmp->next->next;
        delete tmp->next;
        tmp->next = a;
        a->prev = tmp;

        return head;
    }

    // Destroy
    static void destroy(Node *head)
    {
        if (head == NULL)
            return;

        if (head->next == head)
        {
            delete head;
            return;
        }

        Node *tmp = head;
        while (tmp->next != head)
        {
            Node *a = tmp->next;
            delete tmp;
            tmp = a;
        }
        delete tmp;
    }
};