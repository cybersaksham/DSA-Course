/*
Time Complexities:
1. show()               Printing all values             O(n)
2. setVal()             Taking input for all values     O(n)
3. orderInsertion()     Insert value in order           O(n)
4. disorderInsertion()  Insert value without order      O(1)
5. orderDeletion()      Delete value in order           O(n)
6. disorderDeletion()   Delete value without order      O(1)
*/

#include <iostream>
using namespace std;

class MyArr
{
    int total_size, used_size, *base;

public:
    MyArr(int tSize)
    {
        total_size = tSize;
        used_size = 0;
        base = new int[tSize];
    }

    // Showing values of ADT
    void show()
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << base[i] << " ";
        }
        cout << endl;
    }

    // Setting all values of ADT
    void setVal(int uSize)
    {
        if (uSize > total_size)
            return;
        used_size = uSize;
        int n;
        for (int i = 0; i < used_size; i++)
        {
            cout << "Enter element no " << i << " = ";
            cin >> n;
            base[i] = n;
        }
    }

    // Inserting in order of ADT
    int orderInsertion(int index, int element)
    {
        if (used_size == total_size)
            return 0;

        for (int i = used_size - 1; i >= index; i--)
        {
            base[i + 1] = base[i];
        }
        base[index] = element;
        used_size++;
        return 1;
    }

    // Inserting without order of ADT
    int disorderInsertion(int index, int element)
    {
        if (used_size == total_size)
            return 0;

        base[used_size] = base[index];
        base[index] = element;
        used_size++;
        return 1;
    }

    // Deleting in order of ADT
    int orderDeletion(int index)
    {
        if (used_size <= index)
            return 0;

        for (int i = index; i < used_size - 1; i++)
        {
            base[i] = base[i + 1];
        }
        used_size--;
        return 1;
    }

    // Deleting without order of ADT
    int disorderDeletion(int index)
    {
        if (used_size <= index)
            return 0;

        base[index] = base[used_size - 1];
        used_size--;
        return 1;
    }
};

int main()
{
    MyArr marks(10);
    marks.setVal(5);
    marks.show();

    // Inserting by Order
    if (marks.orderInsertion(3, 25))
    {
        cout << "Insertion Succeeded" << endl;
    }
    else
    {
        cout << "Insertion Failed" << endl;
    }
    marks.show();

    // Inserting without Order
    if (marks.disorderInsertion(1, 100))
    {
        cout << "Insertion Succeeded" << endl;
    }
    else
    {
        cout << "Insertion Failed" << endl;
    }
    marks.show();

    // Deleting by Order
    if (marks.orderDeletion(3))
    {
        cout << "Deletion Succeeded" << endl;
    }
    else
    {
        cout << "Deletion Failed" << endl;
    }
    marks.show();

    // Deleting without Order
    if (marks.disorderDeletion(1))
    {
        cout << "Deletion Succeeded" << endl;
    }
    else
    {
        cout << "Deletion Failed" << endl;
    }
    marks.show();

    return 0;
}