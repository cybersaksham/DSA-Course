#include <iostream>
#include <queue>
#include "Queue_by_array.h"
#include "Queue_by_dynamic_array.h"
#include "Queue_by_linked_list.h"
using namespace std;

int main()
{
    // In-built Queue
    cout << "In-Built Queue" << endl;
    queue<int> q1;
    q1.push(20);
    q1.push(30);
    q1.push(40);
    cout << q1.front() << endl;
    q1.pop();
    cout << q1.front() << endl;
    cout << q1.size() << endl;
    cout << q1.empty() << endl;
    cout << endl;

    // Queue by fixed size array
    cout << "Queue by fixed size array" << endl;
    QueueByArray<int> q2(3);
    q2.enqueue(100);
    q2.enqueue(200);
    q2.enqueue(300);
    q2.enqueue(400);
    cout << q2.front() << endl;
    q2.dequeue();
    cout << q2.front() << endl;
    q2.dequeue();
    q2.enqueue(500);
    cout << q2.front() << " " << q2.getSize() << endl;
    q2.destroy();
    cout << endl;

    // Queue by dynamic size array
    cout << "Queue by dynamic size array" << endl;
    QueueByDynamicArray<int> q3;
    q3.enqueue(100);
    q3.enqueue(200);
    q3.enqueue(300);
    q3.enqueue(400);
    q3.enqueue(500);
    q3.enqueue(600);
    cout << q3.front() << endl;
    q3.dequeue();
    cout << q3.front() << endl;
    q3.dequeue();
    cout << q3.getSize() << endl;
    q3.destroy();
    cout << endl;

    // Queue by Linked List
    cout << "Queue by Linked List" << endl;
    QueueByLL<int> q4;
    q4.enqueue(100);
    q4.enqueue(200);
    q4.enqueue(300);
    q4.enqueue(400);
    q4.enqueue(500);
    q4.enqueue(600);
    cout << q4.front() << endl;
    q4.dequeue();
    cout << q4.front() << endl;
    q4.dequeue();
    cout << q4.getSize() << endl;
    cout << endl;

    // Copying
    cout << "Copying" << endl;
    QueueByLL<int> q5(q4);
    q5.dequeue();
    cout << q4.front() << " " << q5.front() << endl;

    q4.destroy();
    q5.destroy();

    return 0;
}