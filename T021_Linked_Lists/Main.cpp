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

    // Inserting after a node
    head->getNext()->insert(15);
    Node<int>::print(head);

    // Deletion at index
    head = Node<int>::remove(head, 6);
    Node<int>::print(head);

    // Deletion at a node
    head = head->getNext()->remove(head);
    Node<int>::print(head);

    // Recursive Insertion
    head = Node<int>::insertRecursive(head, 1, 90);
    Node<int>::print(head);

    // Recursive Deletion
    head = Node<int>::removeRecursive(head, 2);
    Node<int>::print(head);

    // Calculating Lenght
    cout << Node<int>::length(head) << endl;
    cout << Node<int>::lengthRecur(head) << endl;

    // Value at index i
    cout << Node<int>::valueAt(head, 3) << endl;

    Node<int>::destroy(head);

    return 0;
}