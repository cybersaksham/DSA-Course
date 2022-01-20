#include <iostream>
using namespace std;

class Student
{
    int id;
    const int rollNo;
    int &idRef;

public:
    Student(int id, int rollNo) : id(id), rollNo(rollNo), idRef(this->id)
    {
    }

    void print()
    {
        cout << this->id << " " << this->rollNo << " " << this->idRef << endl;
    }
};

int main()
{
    Student s1(1, 101);
    s1.print();

    return 0;
}