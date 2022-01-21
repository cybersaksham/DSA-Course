/*
You have been given a head to a singly linked list of integers. Write a function check to whether the list given is a 'Palindrome' or not.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First and the only line of each test case or query contains the the elements of the singly linked list separated by a single space.

Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element.

*/

#include <iostream>
#include "./Node.cpp"
using namespace std;

bool Node::checkPalindrome(Node *head)
{
    Node *reversed = NULL;
    Node *tmp = head;

    while (tmp != NULL)
    {
        Node *newNode = new Node(tmp->data, reversed);
        tmp = tmp->next;
        reversed = newNode;
    }

    Node *tmp2 = head;
    Node *tmp3 = reversed;

    while (tmp2 != NULL && tmp3 != NULL)
    {
        if (tmp2->data != tmp3->data)
        {
            Node::destroy(reversed);
            return false;
        }

        tmp2 = tmp2->next;
        tmp3 = tmp3->next;
    }

    Node::destroy(reversed);
    return true;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = Node::input();

        cout << Node::checkPalindrome(head) << endl;

        Node::destroy(head);
    }

    return 0;
}