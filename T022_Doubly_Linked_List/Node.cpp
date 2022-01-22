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
    Node(T data) : prev(NULL), data(data), next(NULL) {}
    Node(Node *prev, T data) : prev(prev), data(data), next(NULL) {}
    Node(T data, Node *next) : prev(NULL), data(data), next(next) {}
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
        head = head->findHead();

        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }

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

        return head;
    }

    // Find Head
    Node *findHead()
    {
        Node *tmp = this;
        while (tmp != NULL && tmp->prev != NULL)
            tmp = tmp->prev;
        return tmp;
    }

    // Insertion at index i
    static Node *insert(Node *head, int i, T data)
    {
        if (i == 0)
        {
            Node *tmp = NULL;
            if (head != NULL)
                tmp = head->prev;
            Node *newNode = new Node(tmp, data, head);
            return newNode;
        }

        Node *tmp = head;
        while (tmp != NULL && --i)
        {
            tmp = tmp->next;
        }

        if (tmp == NULL)
        {
            throw out_of_range("Index out of range");
        }

        Node *newNode = new Node(tmp, data, tmp->next);
        if (tmp->next != NULL)
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
            delete head;
            if (a != NULL)
                a->prev = b;
            if (b != NULL)
                b->next = a;
            return a;
        }

        Node *tmp = head;
        while (tmp != NULL && --i)
        {
            tmp = tmp->next;
        }

        if (tmp == NULL || tmp->next == NULL)
        {
            throw out_of_range("Index out of range");
        }

        Node *a = tmp->next->next;
        delete tmp->next;
        tmp->next = a;
        if (a != NULL)
            a->prev = tmp;

        return head;
    }

    // Destroy
    static void destroy(Node *head)
    {
        head = head->findHead();

        while (head != NULL)
        {
            Node *a = head->next;
            delete head;
            head = a;
        }
    }
};