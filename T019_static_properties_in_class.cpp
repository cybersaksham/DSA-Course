#include <iostream>
using namespace std;

class Student
{
    int id;
    int rollNo;
    static int totalStudents;

public:
    Student(int id, int rollNo) : id(id), rollNo(rollNo)
    {
        Student::totalStudents++;
    }

    static int getStudents()
    {
        return totalStudents;
    }
};

int Student::totalStudents = 0;

int main()
{
    Student s1(1, 10);
    Student s2(2, 20);

    cout << Student::getStudents() << endl;

    return 0;
}