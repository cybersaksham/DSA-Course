/*
Given an expression (Take Input) => (2 + {3 - 5} - [5 + (2 * 4)])
Find that expression has correct parenthesis opening & closing or not.
*/

#include <iostream>
#include <string>
using namespace std;

class Stack
{
    int size, top;
    char *arr;
    string exp;

public:
    Stack(int size, string exp)
    {
        this->size = size;
        this->top = -1;
        this->arr = new char[size];
        this->exp = exp;
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

    int checkReversed(char c1, char c2)
    {
        if (c1 == '{' && c2 == '}')
            return 1;
        else if (c1 == '[' && c2 == ']')
            return 1;
        else if (c1 == '(' && c2 == ')')
            return 1;
        return 0;
    }

    int checkBalanced()
    {
        for (int i = 0; i < this->exp.size(); i++)
        {
            char ch = this->exp.at(i);
            if (ch == '{' || ch == '(' || ch == '[')
            {
                this->push_back(ch);
            }
            else if (ch == '}' || ch == ')' || ch == ']')
            {
                if (this->stackTop() == '0')
                    return 2;
                if (!this->checkReversed(this->stackTop(), ch))
                    return 1;
                if (!this->pop_back())
                    return 2;
            }
        }
        if (this->top == -1)
            return 0;
        return 3;
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
    string *results = new string[4];
    results[0] = "Expression is balanced.";
    results[1] = "Unbalanced because invalid closing parenthesis found.";
    results[2] = "Unbalanced because un-necessary closing parenthesis found.";
    results[3] = "Unbalanced because some parenthesis remained opened.";
    cout << results[s1.checkBalanced()] << endl;

    return 0;
}