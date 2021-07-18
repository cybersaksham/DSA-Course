/*
    a1  a2  a3  a4.........ai
                            ^
                            f,b
We use array as circular to use efficiently.
*/

/*
Time Complexities (Queue)
1. isEmpty()        Checking for empty      O(1)
2. isFull()         Checking for full       O(1)
3. enqueue()        Insert at last          O(1)
4. dequeue()        Delete from start       O(1)
5. peek()           Getting an index        O(1)
6. show()           printing all values     O(n)
*/

#include <iostream>
using namespace std;

class Queue
{
    int frontInd, backInd, size, empty, full;
    int *arr;

    int peek(int index) { return this->arr[index]; }

public:
    Queue(int size)
    {
        this->size = size;
        this->frontInd = size - 1;
        this->backInd = size - 1;
        this->empty = 1;
        this->full = 0;
        this->arr = new int[size];
    };

    int isEmpty() { return this->empty; }
    int isFull() { return this->full; }

    int enqueue(int element)
    {
        if (this->isFull())
            return -1;
        this->backInd = (this->backInd + 1) % size;
        this->full = this->backInd == this->frontInd;
        this->empty = 0;
        this->arr[this->backInd] = element;
        return element;
    }

    int dequeue()
    {
        if (this->isEmpty())
            return -1;
        this->frontInd = (this->frontInd + 1) % this->size;
        this->empty = this->backInd == this->frontInd;
        this->full = 0;
        return this->arr[this->frontInd];
    }

    void show()
    {
        int a = this->frontInd;
        if (this->isEmpty())
            return;
        do
        {
            a = (a + 1) % this->size;
            cout << this->peek(a) << " ";
        } while (a != this->backInd);
        cout << endl;
    }
};

int main()
{
    Queue q1(10);

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

    // Inserting after deleting
    for (int i = 3; i > 0; i--)
    {
        int a = q1.enqueue(i);
        if (a == -1)
            cout << "Queue overflow at element " << i << endl;
        else
            cout << "Element " << a << " added" << endl;
    }
    q1.show();

    return 0;
}