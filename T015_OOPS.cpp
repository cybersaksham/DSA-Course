#include <iostream>
using namespace std;

class Student
{
    int id;

public:
    int rollNo;

    Student()
    {
        cout << "Constructor 1" << endl;
    }

    Student(int rollNo)
    {
        cout << "Constructor 2" << endl;
        this->rollNo = rollNo;
    }

    Student(int id, int rollNo)
    {
        cout << "Constructor 3" << endl;
        this->id = id;
        this->rollNo = rollNo;
    }

    ~Student()
    {
        cout << "Destructor" << endl;
    }
};

int main()
{
    // Static Objects
    Student s1;
    Student s2(5);

    // Dynamic Objects
    Student *s3 = new Student(5, 15);

    // Accessing Variables
    cout << s2.rollNo << endl;
    cout << s3->rollNo << endl;
    cout << (*s3).rollNo << endl;

    // Copy Constructor
    Student s4(s2);
    Student *s5 = new Student(*s3);

    // Copy Assingment Operator
    *s5 = s1;

    delete s3;
    delete s5;

    return 0;
}