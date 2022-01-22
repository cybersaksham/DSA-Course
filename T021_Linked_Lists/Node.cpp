#include <iostream>
using namespace std;

template <typename T>
class Node
{
    T data;
    Node *next;

public:
    // Constructors
    Node(T data) : data(data), next(NULL) {}
    Node(T data, Node *next) : data(data), next(next) {}

    // Getter for data
    T getData() const { return this->data; }

    // Getter for next
    Node *getNext() const { return this->next; }

    // Setter for data
    void setData(T data) { this->data = data; }

    // Setter for next
    void setNext(Node *next) { this->next = next; }

    // Print Complete List
    static void print(Node *head)
    {
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

            Node *newNode = new Node(a);

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

    // Insertion at index i
    static Node *insert(Node *head, int i, T data)
    {
        if (i == 0)
        {
            Node *newNode = new Node(data, head);
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

        Node *newNode = new Node(data, tmp->next);
        tmp->next = newNode;

        return head;
    }

    // Insertion after a node
    void insert(T data)
    {
        if (this == NULL)
        {
            throw out_of_range("Index out of range");
        }

        Node *newNode = new Node(data, this->next);
        this->next = newNode;
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
            delete head;
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

        return head;
    }

    // Deletion at a node
    Node *remove(Node *head)
    {
        if (head == NULL)
        {
            throw out_of_range("Index out of range");
        }

        if (this == head)
        {
            Node *a = this->next;
            delete this;
            return a;
        }

        Node *tmp = head;
        while (tmp != NULL && tmp->next != NULL && tmp->next != this)
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

        return head;
    }

    // Recursive Insertion at index i
    static Node *insertRecursive(Node *head, int i, T data)
    {
        if (i == 0)
        {
            Node *newNode = new Node(data, head);
            return newNode;
        }

        if (head == NULL)
        {
            throw out_of_range("Index out of range");
        }

        Node *newHead = insertRecursive(head->next, i - 1, data);
        head->next = newHead;
        return head;
    }

    // Recursive Deletion at index i
    static Node *removeRecursive(Node *head, int i)
    {
        if (head == NULL)
        {
            throw out_of_range("Index out of range");
        }

        if (i == 0)
        {
            Node *a = head->next;
            delete head;
            return a;
        }

        Node *newHead = removeRecursive(head->next, i - 1);
        head->next = newHead;
        return head;
    }

    // Calculating Length
    static int length(Node *head)
    {
        int count = 0;

        while (head != NULL)
        {
            count++;
            head = head->next;
        }

        return count;
    }

    // Calculating Length Recursively
    static int lengthRecur(Node *head)
    {
        if (head == NULL)
            return 0;

        return 1 + lengthRecur(head->next);
    }

    // Value at index i
    static T valueAt(Node *head, int i)
    {
        Node *tmp = head;
        while (tmp != NULL && i--)
        {
            tmp = tmp->next;
        }

        if (tmp == NULL)
        {
            throw out_of_range("Index out of range");
        }

        return tmp->data;
    }

    // Destroy
    static void destroy(Node *head)
    {
        while (head != NULL)
        {
            Node *a = head->next;
            delete head;
            head = a;
        }
    }
};