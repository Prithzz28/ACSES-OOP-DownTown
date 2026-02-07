#include <iostream>
using namespace std;

class Addition
{
public:
    int sum(int a, int b)
    {
        return a + b;
    }
    int sum(int a, int b, int c)
    {
        return a + b + c;
    }

    double sum(double a, double b)
    {
        return a + b;
    }
};

int main()
{
    Addition a;
    cout << a.sum(2, 3) << endl;
    cout << a.sum(2, 4, 5) << endl;
    cout << a.sum(2.3, 4.5) << endl;

    return 0;
}