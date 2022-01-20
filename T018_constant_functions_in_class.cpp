#include <iostream>
using namespace std;

class Student
{
    int id;
    int rollNo;

public:
    Student(int id, int rollNo) : id(id), rollNo(rollNo) {}

    void print() const
    {
        cout << this->id << " " << this->rollNo << " " << endl;
    }
};

int main()
{
    Student const s1(1, 10);
    s1.print();

    return 0;
}