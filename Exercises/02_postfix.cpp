/*
Given an infix expression (Take Input) => x-y/z-k*d
Convert it into postfix expression.
*/

#include <iostream>
#include <string>
using namespace std;

class Stack
{
    int size, top;
    char *arr;
    string infix;
    string postfix;

public:
    Stack(int size, string exp)
    {
        this->size = size;
        this->top = -1;
        this->arr = new char[size];
        this->infix = exp;
        this->postfix = "";
    }

    int isEmpty() { return this->top == -1; }

    int isFull() { return this->top == this->size - 1; }

    char stackTop()
    {
        if (this->isEmpty())
        {
            return '0';
        }
        return this->arr[this->top];
    }

    void push_back(char element)
    {
        if (this->isFull())
        {
            return;
        }
        this->arr[++this->top] = element;
    }

    int pop_back()
    {
        if (this->isEmpty())
        {
            return 0;
        }
        this->top--;
        return 1;
    }

    int checkPrecedence(char c1, char c2)
    {
        if ((c1 == '/' || c1 == '*') && (c2 == '/' || c2 == '*'))
            return 0;
        else if (
            (c1 == '*' || c1 == '/' || c1 == '+' || c1 == '-') &&
            (c2 == '-' || c2 == '+'))
            return 0;
        return 1;
    }

    string convert()
    {
        for (int i = 0; i < this->infix.size(); i++)
        {
            char ch = this->infix.at(i);
            if (ch == '*' || ch == '/' || ch == '-' || ch == '+')
            {
                char ch_prev = this->stackTop();
                while (!this->checkPrecedence(ch_prev, ch))
                {
                    string s(1, ch_prev);
                    this->postfix.append(s);
                    this->pop_back();
                    ch_prev = this->stackTop();
                }
                this->push_back(ch);
            }
            else
            {
                string s(1, ch);
                this->postfix.append(s);
            }
        }
        while (!this->isEmpty())
        {
            char ch_prev = this->stackTop();
            string s(1, ch_prev);
            this->postfix.append(s);
            this->pop_back();
        }
        return this->postfix;
    }
};

int main()
{
    // Input for expression
    cout << "Enter an expression : ";
    string exp;
    getline(cin, exp);

    // Making stack
    Stack s1(exp.size(), exp);

    // Printing result
    cout << "Postfix expression: " << s1.convert() << endl;

    return 0;
}