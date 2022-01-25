/*
You have been given a queue that can store integers as the data. You are required to write a function that reverses the populated queue itself without using any other data structures.

Input Format:
The first list of input contains an integer 't' denoting the number of test cases/queries to be run.
Then the test cases follow.

The first line input for each test case/query contains an integer N, denoting the total number of elements in the queue.

The second line of input contains N integers separated by a single space, representing the order in which the elements are enqueued into the queue.
*/

#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q)
{
    if (q.empty() || q.size() == 1)
        return;

    int x = q.front();
    q.pop();

    reverseQueue(q);
    q.push(x);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        queue<int> q;

        int n;
        cin >> n;
        while (n--)
        {
            int a;
            cin >> a;
            q.push(a);
        }

        reverseQueue(q);

        while (!q.empty())
        {
            cout << q.front() << " ";
            q.pop();
        }
        cout << endl;
    }

    return 0;
}