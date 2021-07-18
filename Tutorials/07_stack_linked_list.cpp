/*
|       |
|       |
|  a3   | <-- top = 3
|  a2   |
|  a1   |
|  a0   |
|_______|
*/

/*
Time Complexities (Stack)
1. isEmpty()        Checking for empty              O(1)
2. isFull()         Checking for full               O(1)
3. push()           Insert at top                   O(1)
4. pop()            Delete from top                 O(1)
5. peek()           Getting an index                O(n)
6. show()           printing all values             O(n)
7. stackTop()       Printing topmost element        O(1)
8. stackBottom()    Printing bottommost element     O(n)
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

    int getData() { return this->data; }
    Node *getNext() { return this->next; }

    int traversal(int index)
    {
        Node *ptr = this;
        for (int i = 0; i < index - 1 && ptr != NULL; i++)
        {
            ptr = ptr->next;
        }
        if (ptr != NULL)
            return ptr->data;
        return 0;
    }

    void show()
    {
        Node *ptr = this;
        for (int i = 1; ptr != NULL; i++)
        {
            cout << this->traversal(i) << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }

    Node *push(int element)
    {
        Node *newNode = new Node[sizeof(Node)];
        newNode->setData(element, this);
        return newNode;
    }

    Node *pop()
    {
        Node *ptr = this->next;
        delete this;
        return ptr;
    }
};

class Stack
{
    Node *top;
    Node *arr;

public:
    Stack()
    {
        this->top = NULL;
        this->arr = new Node[sizeof(Node)];
    }

    int isEmpty() { return this->top == NULL; }

    int isFull()
    {
        Node *newNode = new Node[sizeof(Node)];
        return newNode == NULL;
    }

    void push(int element)
    {
        if (this->isFull())
        {
            cout << "Stack overflow at value " << element << endl;
            return;
        }
        this->top = this->top->push(element);
    }

    void pop()
    {
        if (this->isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        this->top = this->top->pop();
    }

    int peek(int position)
    {
        if (this->isEmpty())
        {
            return 0;
        }
        return this->top->traversal(position);
    }

    void show() { this->top->show(); }

    int stackTop()
    {
        if (this->isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        return this->top->getData();
    }

    int stackBottom()
    {
        if (this->isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        Node *ptr = this->top;
        while (ptr->getNext() != NULL)
        {
            ptr = ptr->getNext();
        }
        return ptr->getData();
    }
};

int main()
{
    Stack s1;

    // Inserting Elements
    s1.push(50);
    s1.push(40);
    s1.push(-5);
    s1.push(10);
    s1.push(2);
    s1.push(-1);
    s1.show();

    // Popping Elements
    s1.pop();
    s1.pop();
    s1.show();

    // Peek
    cout << s1.peek(2) << endl;

    // Top & Bottom
    cout << s1.stackTop() << endl;
    cout << s1.stackBottom() << endl;

    return 0;
}