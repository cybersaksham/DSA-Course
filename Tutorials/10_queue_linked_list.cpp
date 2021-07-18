/*
    Deletion End                         Insertion End
    |                                    |
    a1 --> a2 --> a3 --> a4 -->......--> ai --> NULL
    ^                                     ^
    f                                     b
After enqueue backind increases & after dequeue frontind increases.
Initially frontind & backind are NULL.
*/

/*
Time Complexities (Queue)
1. isEmpty()        Checking for empty      O(1)
2. isFull()         Checking for full       O(1)
3. enqueue()        Insert at last          O(1)
4. dequeue()        Delete from start       O(1)
5. peek()           Getting an index        O(n)
6. show()           printing all values     O(n)
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void setData(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

class Queue
{
    Node *frontInd, *backInd;

public:
    Queue()
    {
        this->frontInd = NULL;
        this->backInd = NULL;
    };

    int isEmpty() { return this->frontInd == NULL; }
    int isFull() { return new Node[sizeof(Node)] == NULL; }

    int enqueue(int element)
    {
        if (this->isFull())
            return -1;
        Node *newNode = new Node[sizeof(Node)];
        newNode->setData(element, NULL);
        if (this->isEmpty())
            this->frontInd = newNode;
        else
            this->backInd->next = newNode;
        this->backInd = newNode;
        return element;
    }

    int dequeue()
    {
        if (this->isEmpty())
            return -1;
        Node *ptr = this->frontInd;
        int element = ptr->data;
        this->frontInd = this->frontInd->next;
        if (this->isEmpty())
            this->backInd = NULL;
        delete ptr;
        return element;
    }

    int peek(int index)
    {
        if (index < 1 || this->isEmpty())
            return -1;
        Node *ptr = this->frontInd;
        for (int i = 0; i < index - 1; i++)
        {
            ptr = ptr->next;
            if (ptr == NULL)
                return -1;
        }
        return ptr->data;
    }

    void show()
    {
        if (this->isEmpty())
            return;
        Node *ptr = this->frontInd;
        do
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        } while (ptr != NULL);
        cout << endl;
    }
};

int main()
{
    Queue q1;

    // Inserting
    for (int i = 11; i > 0; i--)
    {
        int a = q1.enqueue(i);
        if (a == -1)
            cout << "Queue overflow at element " << i << endl;
        else
            cout << "Element " << a << " added" << endl;
    }
    q1.show();

    // Deleting
    for (int i = 0; i < 2; i++)
    {
        int a = q1.dequeue();
        if (a == -1)
            cout << "Queue underflow" << endl;
        else
            cout << "Removed element " << a << endl;
    }
    q1.show();

    // Peek
    cout << q1.peek(2) << endl;

    return 0;
}