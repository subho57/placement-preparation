#include <bits/stdc++.h>
using namespace std;
class Complex
{
public:
    int real;
    int imaginary;

    Complex()
    {
        this->real = 0;
        this->imaginary = 0;
    }

    Complex(int r, int i)
    {
        this->real = r;
        this->imaginary = i;
    }
};

Complex *Add(Complex *obj1, Complex *obj2)
{
    Complex *obj = new Complex(0.0, 0.0);
    obj->real = obj1->real + obj2->real;
    obj->imaginary = obj1->imaginary + obj2->imaginary;
    return obj;
}

int main(void)
{
    int r, i;
    cout << "Enter Complex Number 1 (e.g: 3+4i): ";
    scanf("%d+%di", &r, &i);
    Complex *obj1 = new Complex(r, i);
    cout << "Enter Complex Number 2 (e.g: 3+4i): ";
    scanf("%d+%di", &r, &i);
    Complex *obj2 = new Complex(r, i);
    Complex *obj = Add(obj1, obj2);
    cout << "Added Complex Number is = " << obj->real << "+" << obj->imaginary << "i\n";
    return 0;
}