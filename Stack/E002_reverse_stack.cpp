/*
You have been given two stacks that can store integers as the data. Out of the two given stacks, one is populated and the other one is empty. You are required to write a function that reverses the populated stack using the one which is empty.
For Example:

Input Format :
The first line of input contains an integer N, denoting the total number of elements in the stack.

The second line of input contains N integers separated by a single space, representing the order in which the elements are pushed into the stack.
*/

#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &st1)
{
    if (st1.empty())
        return;

    int x = st1.top();
    st1.pop();
    reverseStack(st1);

    stack<int> st2;

    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }

    st1.push(x);

    while (!st2.empty())
    {
        st1.push(st2.top());
        st2.pop();
    }
}

int main()
{
    stack<int> st1;

    int n;
    cin >> n;
    while (n--)
    {
        int a;
        cin >> a;
        st1.push(a);
    }

    reverseStack(st1);

    while (!st1.empty())
    {
        cout << st1.top() << " ";
        st1.pop();
    }
    cout << endl;

    return 0;
}