/*
Enqueue & Dequeue can be done from both sides.
*/

/*
Time Complexities (DEQueue)
1. isEmpty()        Checking for empty      O(1)
2. isFull()         Checking for full       O(1)
3. enqueueF()       Insert at last          O(1)
4. dequeueF()       Delete from start       O(1)
5. enqueueR()       Insert at last          O(1)
6. dequeueR()       Delete from start       O(1)
7. peek()           Getting an index        O(1)
8. show()           printing all values     O(n)
*/

#include <iostream>
using namespace std;

class DEQueue
{
    int frontInd, backInd, size;
    int *arr;

public:
    DEQueue(int size)
    {
        this->size = size;
        this->frontInd = -1;
        this->backInd = -1;
        this->arr = new int[size];
    };

    int isEmpty() { return this->frontInd == this->backInd; }
    int isFull() { return this->backInd == this->size - 1; }

    int enqueueF(int element)
    {
        if (this->frontInd == -1)
            return -1;
        this->arr[this->frontInd--] = element;
        return element;
    }

    int enqueueR(int element)
    {
        if (this->isFull())
            return -1;
        this->arr[++this->backInd] = element;
        return element;
    }

    int dequeueF()
    {
        if (this->isEmpty())
            return -1;
        return this->arr[++this->frontInd];
    }

    int dequeueR()
    {
        if (this->isEmpty())
            return -1;
        return this->arr[this->backInd--];
    }

    int peek(int index)
    {
        if (index < 1 || index > this->backInd - this->frontInd)
            return 0;
        return this->arr[this->frontInd + index];
    }

    void show()
    {
        for (int i = 1; i <= this->backInd - this->frontInd; i++)
        {
            cout << this->peek(i) << " ";
        }
        cout << endl;
    }
};

int main()
{
    DEQueue q1(10);

    // Inserting from End
    for (int i = 11; i > 0; i--)
    {
        int a = q1.enqueueR(i);
        if (a == -1)
            cout << "Queue overflow at element " << i << endl;
        else
            cout << "Element " << a << " added" << endl;
    }
    q1.show();

    // Deleting from Start
    for (int i = 0; i < 2; i++)
    {
        int a = q1.dequeueF();
        if (a == -1)
            cout << "Queue underflow" << endl;
        else
            cout << "Removed element " << a << endl;
    }
    q1.show();

    // Inserting from Start
    for (int i = 5; i > 0; i--)
    {
        int a = q1.enqueueF(i);
        if (a == -1)
            cout << "Queue overflow at element " << i << endl;
        else
            cout << "Element " << a << " added" << endl;
    }
    q1.show();

    // Deleting from Start
    for (int i = 0; i < 2; i++)
    {
        int a = q1.dequeueF();
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