#include <iostream>
using namespace std;

// Abstract class
class ATM {
public:
    virtual void withdraw() = 0;   // Pure virtual function
    virtual void checkBalance() = 0;
};

// Derived class
class SBI : public ATM {
private:
    int balance = 5000;   // Hidden data

public:
    void withdraw() {
        int amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;

        if(amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful!" << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void checkBalance() {
        cout << "Your balance is: " << balance << endl;
    }
};

int main() {
    ATM* atm;       // Base class pointer
    SBI sbi;        // Object of derived class
    atm = &sbi;

    int choice;

    cout << "1. Withdraw\n2. Check Balance\n";
    cout << "Enter choice: ";
    cin >> choice;

    if(choice == 1)
        atm->withdraw();
    else if(choice == 2)
        atm->checkBalance();
    else
        cout << "Invalid choice";

    return 0;
}
