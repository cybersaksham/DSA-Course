/*
        Deletion End            Insertion End
        |                       |
        a1  a2  a3  a4.........ai
    ^                           ^
    f                           b
After enqueue backind increases & after dequeue frontind increases.
Hence size of array decreases continuously so we will use circular queue.
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
    int frontInd, backInd, size;
    int *arr;

public:
    Queue(int size)
    {
        this->size = size;
        this->frontInd = -1;
        this->backInd = -1;
        this->arr = new int[size];
    };

    int isEmpty() { return this->frontInd == this->backInd; }
    int isFull() { return this->backInd == this->size - 1; }

    int enqueue(int element)
    {
        if (this->isFull())
            return -1;
        this->arr[++this->backInd] = element;
        return element;
    }

    int dequeue()
    {
        if (this->isEmpty())
            return -1;
        return this->arr[++this->frontInd];
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

    // Peek
    cout << q1.peek(2) << endl;

    return 0;
}