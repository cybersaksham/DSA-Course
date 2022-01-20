#include <bits/stdc++.h>
using namespace std;

class Fraction
{
    int isNegative;
    int numerator;
    int denominator;

    void simplify(int num, int den)
    {
        if (den == 0)
            throw invalid_argument("Denominator cannot be zero");

        (num * den) < 0 ? this->isNegative = 1 : this->isNegative = 0;

        num = abs(num);
        den = abs(den);

        if (num == 0)
        {
            this->numerator = this->denominator = 0;
        }
        else
        {
            int gcd = __gcd(num, den);

            this->numerator = num / gcd;
            this->denominator = den / gcd;
        }
    }

    int getNumerator() const
    {
        return this->isNegative ? -1 * this->numerator : this->numerator;
    }

public:
    Fraction(int num, int den) { simplify(num, den); }

    // + Operator
    Fraction operator+(Fraction const &f1) const
    {
        int den = this->denominator * f1.denominator;
        int num1 = this->getNumerator();
        int num2 = f1.getNumerator();
        int num = (num1 * f1.denominator) + (num2 * this->denominator);

        Fraction fNew(num, den);
        return fNew;
    }

    // - Operator
    Fraction operator-(Fraction const &f1) const
    {
        int den = this->denominator * f1.denominator;
        int num1 = this->getNumerator();
        int num2 = f1.getNumerator();
        int num = (num1 * f1.denominator) - (num2 * this->denominator);

        Fraction fNew(num, den);
        return fNew;
    }

    // * Operator
    Fraction operator*(Fraction const &f1) const
    {
        int den = this->denominator * f1.denominator;
        int num1 = this->getNumerator();
        int num2 = f1.getNumerator();
        int num = num1 * num2;

        Fraction fNew(num, den);
        return fNew;
    }

    // / Operator
    Fraction operator/(Fraction const &f1) const
    {
        int num1 = this->getNumerator();
        int num2 = f1.getNumerator();
        int den = this->denominator * num2;
        int num = num1 * f1.denominator;

        Fraction fNew(num, den);
        return fNew;
    }

    // Pre Increment
    Fraction &operator++()
    {
        int num = this->getNumerator();
        int den = this->denominator;
        simplify(num + den, den);
        return *this;
    }

    // Post Increment
    Fraction &operator++(int)
    {
        int num = this->getNumerator();
        int den = this->denominator;
        simplify(num + den, den);

        Fraction *fNew = new Fraction(num, den);
        return *fNew;
    }

    // Pre Decrement
    Fraction &operator--()
    {
        int num = this->getNumerator();
        int den = this->denominator;
        simplify(num - den, den);
        return *this;
    }

    // Post Decrement
    Fraction &operator--(int)
    {
        int num = this->getNumerator();
        int den = this->denominator;
        simplify(num - den, den);

        Fraction *fNew = new Fraction(num, den);
        return *fNew;
    }

    void print() const
    {
        cout << this->getNumerator() << " / " << this->denominator << endl;
    }
};

int main()
{
    Fraction f1(-5, 2);
    Fraction f2(7, -4);
    Fraction f3(8, 3);
    Fraction f4(3, 5);
    Fraction f5(2, 7);

    Fraction f6 = f1 + f2 - f3 * f4 / f5;
    f6.print();

    Fraction f7 = ++(++f1);
    f1.print();
    f7.print();

    Fraction f8 = (f2++)++;
    f2.print();
    f8.print();

    return 0;
}