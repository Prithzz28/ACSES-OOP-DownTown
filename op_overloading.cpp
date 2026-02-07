#include <iostream>
using namespace std;

class Complex
{
public:
    float real;
    float imag;

    Complex(float r = 0, float i = 0)
    {
        real = r;
        imag = i;
    }

    // Operator overloading for +
    Complex operator+ (const Complex &obj)
    {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }
};

int main()
{
    // Create two Complex objects
    Complex c1(3.5, 2.5);
    Complex c2(1.5, 4.5);

    // Add them using overloaded + operator
    Complex c3 = c1 + c2;

    // Display the result
    cout << "Result: ";
    cout << c3.real << " + " << c3.imag << "i" << endl;

    return 0;
}
