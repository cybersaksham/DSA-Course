#include <iostream>
#include "./Node.cpp"
using namespace std;

int main()
{
    // Creating Object
    Node<int> *head = Node<int>::input();
    Node<int>::print(head);

    // Inserting at index
    head = Node<int>::insert(head, 0, 50);
    Node<int>::print(head);

    // Deletion at index
    head = Node<int>::remove(head, 2);
    Node<int>::print(head);

    Node<int>::destroy(head);

    return 0;
}