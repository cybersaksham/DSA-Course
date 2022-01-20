#include <iostream>
using namespace std;

class Complex
{
    int real, img;

public:
    Complex()
    {
        this->real = 0;
        this->img = 0;
    }

    Complex(int real)
    {
        this->real = real;
        this->img = 0;
    }

    Complex(int real, int img)
    {
        this->real = real;
        this->img = img;
    }

    void add(Complex const &c)
    {
        this->real += c.real;
        this->img += c.img;
    }

    void multiply(Complex const &comp)
    {
        int a = this->real * comp.real;
        int b = this->img * comp.img;
        int c = this->real * comp.img;
        int d = this->img * comp.real;

        this->real = a - b;
        this->img = c + d;
    }

    void print()
    {
        cout << this->real << " ";
        cout << (this->img < 0 ? "-" : "+") << " ";
        cout << (this->img < 0 ? -1 * this->img : this->img) << "i" << endl;
    }
};

int main()
{
    Complex c1(10, 20);
    Complex c2(20, -25);

    c1.print();
    c2.print();

    c1.add(c2);
    c1.print();

    return 0;
}