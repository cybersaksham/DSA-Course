#include <iostream>
#include "MinPQueue.hpp"
#include "MaxPQueue.hpp"
#include <queue>
#include <vector>
#include <functional>
using namespace std;

bool customComp(int a, int b) {
    return (a*a) > (b*b);
}

int main() {
    // Min Priority Queue
    cout << "MIN PRIORITY QUEUE" << endl;
    MinPQueue q1;
    q1.push(5);
    q1.push(2);
    q1.push(3);
    cout << q1.size() << endl;
    cout << q1.top() << endl;
    q1.pop();
    cout << q1.top() << endl;
    q1.pop();
    cout << q1.top() << endl;
    q1.pop();
    cout << q1.size() << endl;

    // Max Priority Queue
    cout << "MAX PRIORITY QUEUE" << endl;
    MaxPQueue q2;
    q2.push(5);
    q2.push(2);
    q2.push(3);
    cout << q2.size() << endl;
    cout << q2.top() << endl;
    q2.pop();
    cout << q2.top() << endl;
    q2.pop();
    cout << q2.top() << endl;
    q2.pop();
    cout << q2.size() << endl;

    // In-Built Max Priority Queue
    cout << "IN-BUILT MAX PRIORITY QUEUE" << endl;
    priority_queue<int> q3;
    q3.push(5);
    q3.push(2);
    q3.push(3);
    cout << q3.size() << endl;
    cout << q3.top() << endl;
    q3.pop();
    cout << q3.top() << endl;
    q3.pop();
    cout << q3.top() << endl;
    q3.pop();
    cout << q3.size() << endl;

    // In-Built Min Priority Queue
    cout << "IN-BUILT MIN PRIORITY QUEUE" << endl;
    priority_queue<int, vector<int>, greater<int>> q4;
    q4.push(5);
    q4.push(2);
    q4.push(3);
    cout << q4.size() << endl;
    cout << q4.top() << endl;
    q4.pop();
    cout << q4.top() << endl;
    q4.pop();
    cout << q4.top() << endl;
    q4.pop();
    cout << q4.size() << endl;

    // In-Built Custom Priority Queue
    cout << "IN-BUILT CUSTOM PRIORITY QUEUE" << endl;
    priority_queue<int, vector<int>, function<bool(int, int)>> q5(customComp);
    q5.push(5);
    q5.push(-2);
    q5.push(-6);
    cout << q5.size() << endl;
    cout << q5.top() << endl;
    q5.pop();
    cout << q5.top() << endl;
    q5.pop();
    cout << q5.top() << endl;
    q5.pop();
    cout << q5.size() << endl;

    return 0;
}