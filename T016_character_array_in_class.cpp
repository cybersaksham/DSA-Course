#include <iostream>
#include <string.h>
using namespace std;

class Student
{
    char *name;

public:
    Student(char *name)
    {
        // Shallow Copy
        // this->name = name;

        // Deep Copy
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
    }

    Student(Student const &s)
    {
        this->name = new char[strlen(s.name) + 1];
        strcpy(this->name, s.name);
    }

    void print()
    {
        cout << this->name << endl;
    }
};

int main()
{
    char name[] = "abcd";

    Student s1(name);

    name[1] = 'x';
    Student s2(name);

    Student s3(s1);

    s1.print();
    s2.print();
    s3.print();

    return 0;
}