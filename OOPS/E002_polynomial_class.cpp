#include <bits/stdc++.h>
using namespace std;

class Polynomial
{
    int *data; // Index 0 is size

    void reallocate(int degree)
    {
        if (this->data[0] >= degree + 1)
            return;

        int *newData = new int[degree + 2];

        for (int i = 1; i <= degree + 1; i++)
        {
            if (i > this->data[0])
                newData[i] = 0;
            else
                newData[i] = this->data[i];
        }

        newData[0] = degree + 1;
        delete this->data;
        this->data = newData;
    }

    void copyValues(Polynomial const &p1)
    {
        this->data = new int[p1.data[0] + 1];
        this->data[0] = p1.data[0];

        for (int i = 1; i <= this->data[0]; i++)
            this->data[i] = p1.data[i];
    }

public:
    Polynomial()
    {
        this->data = new int[1];
        this->data[0] = 0;
    }

    Polynomial(Polynomial const &p1) { this->copyValues(p1); }
    void operator=(Polynomial const &p1) { this->copyValues(p1); }

    void setCoefficient(int degree, int value)
    {
        if (degree < 0)
            throw invalid_argument("Only non negative degree allowed.");

        this->reallocate(degree);
        this->data[degree + 1] = value;
    }

    Polynomial &operator+(Polynomial const &p1)
    {
        Polynomial *pNew = new Polynomial(*this);
        pNew->reallocate(max(pNew->data[0], p1.data[0]));

        for (int i = 1; i <= pNew->data[0]; i++)
        {
            if (i <= p1.data[0])
                pNew->data[i] += p1.data[i];
        }

        return *pNew;
    }

    Polynomial &operator-(Polynomial const &p1)
    {
        Polynomial *pNew = new Polynomial(*this);
        pNew->reallocate(max(pNew->data[0], p1.data[0]));

        for (int i = 1; i <= pNew->data[0]; i++)
        {
            if (i <= p1.data[0])
                pNew->data[i] -= p1.data[i];
        }

        return *pNew;
    }

    void print() const
    {
        if (this->data[0] == 0)
            return;

        if (this->data[1] != 0)
            cout << this->data[1] << "x0 ";

        for (int i = 2; i <= this->data[0]; i++)
        {
            if (this->data[i] != 0)
            {
                cout << (this->data[i] < 0 ? "-" : "+");
                cout << " " << abs(this->data[i]) << "x" << (i - 1) << " ";
            }
        }

        cout << endl;
    }
};

int main()
{
    Polynomial p1;
    p1.setCoefficient(0, 25);
    p1.setCoefficient(1, -10);
    p1.setCoefficient(3, 5);
    p1.setCoefficient(5, -2);
    p1.print();

    Polynomial p2;
    p2.setCoefficient(0, 2);
    p2.setCoefficient(15, 9);
    p2.setCoefficient(3, -15);
    p2.setCoefficient(5, 18);
    p2.print();

    Polynomial p3 = p1 + p2;
    p3.print();

    Polynomial p4 = p1 - p2 + p3;
    p4.print();

    return 0;
}