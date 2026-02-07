#include <iostream>
using namespace std;

class Payment
{
public:
    virtual void pay(int amount)
    {
        cout << "Paying " << amount << " using generic payment method" << endl;
    }
};

class CreditCard : public Payment
{
public:
    void pay(int amount) override
    {
        cout << "Paying " << amount << " using Credit Card" << endl;
    }
};

class UPI : public Payment
{
public:
    void pay(int amount) override
    {
        cout << "Paying " << amount << " using UPI" << endl;
    }
};

class Cash : public Payment
{
public:
    void pay(int amount) override
    {
        cout << "Paying " << amount << " using Cash" << endl;
    }
};
int main()
{
    Payment *p;

    CreditCard cc;
    UPI upi;
    Cash cash;

    p = &cc;
    p->pay(500);

    p = &upi;
    p->pay(1200);

    p = &cash;
    p->pay(300);

    return 0;
}
