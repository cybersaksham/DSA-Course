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
3. push_back()      Insert at top                   O(1)
4. pop_back()       Delete from top                 O(1)
5. peek()           Getting an index                O(1)
6. show()           printing all values             O(n)
7. stackTop()       Printing topmost element        O(1)
8. stackBottom()    Printing bottommost element     O(1)
*/

#include <iostream>
using namespace std;

class Stack
{
    int size, top;
    int *arr;

public:
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->arr = new int[size];
    }

    int isEmpty() { return this->top == -1; }

    int isFull() { return this->top == this->size - 1; }

    void push_back(int element)
    {
        if (this->isFull())
        {
            cout << "Stack overflow at value " << element << endl;
            return;
        }
        this->arr[++this->top] = element;
    }

    void pop_back()
    {
        if (this->isEmpty())
        {
            cout << "Stack underflow" << endl;
            return;
        }
        this->top--;
    }

    int peek(int position)
    {
        if (this->top < position - 1 || position < 1)
            return 0;
        return this->arr[this->top - position + 1];
    }

    void show()
    {
        for (int i = this->top + 1; i > 0; i--)
        {
            cout << this->peek(i) << " ";
        }
        cout << endl;
    }

    int stackTop()
    {
        if (this->isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        return this->arr[this->top];
    }

    int stackBottom()
    {
        if (this->isEmpty())
        {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        return this->arr[0];
    }
};

int main()
{
    Stack s1(5);

    // Inserting Elements
    s1.push_back(50);
    s1.push_back(40);
    s1.push_back(-5);
    s1.push_back(10);
    s1.push_back(2);
    s1.push_back(-1);
    s1.show();

    // Popping Elements
    s1.pop_back();
    s1.pop_back();
    s1.show();

    // Top & Bottom
    cout << s1.stackTop() << endl;
    cout << s1.stackBottom() << endl;

    return 0;
}