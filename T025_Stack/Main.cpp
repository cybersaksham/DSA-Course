#include <iostream>
#include <stack>
#include "Stack_by_array.h"
#include "Stack_by_dynamic_array.h"
#include "Stack_by_linked_list.h"
using namespace std;

int main()
{
    // In-built Stack
    cout << "In-Built Stack" << endl;
    stack<int> s1;
    s1.push(20);
    s1.push(30);
    s1.push(40);
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.size() << endl;
    cout << s1.empty() << endl;
    cout << endl;

    // Stack by fixed size array
    cout << "Stack by fixed size array" << endl;
    StackByArray<int> s2(3);
    s2.push(100);
    s2.push(200);
    s2.push(300);
    s2.push(400);
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.top() << endl;
    s2.pop();
    cout << s2.size() << endl;
    s2.destroy();
    cout << endl;

    // Stack by dynamic size array
    cout << "Stack by dynamic size array" << endl;
    StackByDynamicArray<int> s3;
    s3.push(100);
    s3.push(200);
    s3.push(300);
    s3.push(400);
    s3.push(500);
    s3.push(600);
    cout << s3.top() << endl;
    s3.pop();
    cout << s3.top() << endl;
    s3.pop();
    cout << s3.size() << endl;
    s3.destroy();
    cout << endl;

    // Stack by Linked List
    cout << "Stack by Linked List" << endl;
    StackByLL<int> s4;
    s4.push(100);
    s4.push(200);
    s4.push(300);
    s4.push(400);
    s4.push(500);
    s4.push(600);
    cout << s4.top() << endl;
    s4.pop();
    cout << s4.top() << endl;
    s4.pop();
    cout << s4.getSize() << endl;
    cout << endl;

    // Copying
    cout << "Copying" << endl;
    StackByLL<int> s5(s4);
    s5.pop();
    cout << s4.top() << " " << s5.top() << endl;

    s4.destroy();
    s5.destroy();

    return 0;
}