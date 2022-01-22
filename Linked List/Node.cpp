#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    // Constructors
    Node(int data) : data(data), next(NULL) {}
    Node(int data, Node *next) : data(data), next(next) {}

    // Print Complete List
    static void print(Node *head)
    {
        while (head != NULL)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    // Taking input
    static Node *input()
    {
        Node *head = NULL;
        Node *tail = NULL;

        int a;
        cin >> a;

        while (a != -1)
        {
            Node *newNode = new Node(a);

            if (head == NULL)
            {
                head = tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }

            cin >> a;
        };

        return head;
    }

    // Calculating Length
    static int length(Node *head)
    {
        int count = 0;

        while (head != NULL)
        {
            count++;
            head = head->next;
        }

        return count;
    }

    // Destroy
    static void destroy(Node *head)
    {
        while (head != NULL)
        {
            Node *a = head->next;
            delete head;
            head = a;
        }
    }

    // Exercise Functions
    static int getIndex(Node *, int);
    static Node *appendLastNToFirst(Node *, int);
    static void removeDuplicates(Node *);
    static void printReverseHelp(Node *);
    static void printReverse(Node *);
    static bool checkPalindrome(Node *);
    static int midpoint(Node *);
    static Node *merge(Node *, Node *);
    static Node *mergeTwo(Node *, Node *);
    static Node *mergeSort(Node *);
    static Node *reverseRecursive(Node *);
    static Node *reverseIterative(Node *);
    static int getIndexRecursive(Node *, int);
    static Node *evenAfterOdd(Node *);
    static Node *deleteEveryNNodes(Node *, int, int);
    static Node *swapNodes(Node *, int, int);
    static Node *reverseEachKNodes(Node *, int);
    static Node *bubbleSort(Node *head);
};