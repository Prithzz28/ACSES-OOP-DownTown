#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*1. ABSTRACTION
   Abstract base class defining interface */
class Account {
protected:
    double balance;   // ENCAPSULATION (protected data)

public:
    Account() { balance = 0; }

    virtual void addMoney(double amt) = 0;      // Pure virtual function
    virtual void spendMoney(double amt) = 0;    // Pure virtual function
    virtual void showBalance() = 0;

    virtual ~Account() {}
};

/*2. INHERITANCE
   Wallet inherits from Account */
class Wallet : public Account {
private:
    vector<string> transactions;   // ENCAPSULATION

public:
    // POLYMORPHISM: Overriding abstract methods
    void addMoney(double amt) override {
        balance += amt;
        transactions.push_back("Credit: Rs." + to_string(amt));
        cout << "Money added successfully.\n";
    }

    void spendMoney(double amt) override {
        if (amt > balance) {
            cout << "Insufficient Balance!\n";
            return;
        }
        balance -= amt;
        transactions.push_back("Debit: Rs." + to_string(amt));
        cout << "Payment successful.\n";
    }

    void showBalance() override {
        cout << "Current Balance: Rs." << balance << endl;
    }

    void showHistory() {
        cout << "\nTransaction History:\n";
        for (string t : transactions)
            cout << t << endl;
    }
};

/* USER CLASS */
class User {
private:
    string name;     // ENCAPSULATION
    Account* acc;    // POLYMORPHISM (base class pointer)

public:
    User(string n) {
        name = n;
        acc = new Wallet();   // Runtime binding
    }

    void menu() {
        int choice;
        double amt;

        do {
            cout << "\n--- Digital Wallet Menu ---\n";
            cout << "1. Add Money\n";
            cout << "2. Spend Money\n";
            cout << "3. Check Balance\n";
            cout << "4. Transaction History\n";
            cout << "5. Exit\n";
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "Enter amount: ";
                    cin >> amt;
                    acc->addMoney(amt);   // POLYMORPHISM
                    break;

                case 2:
                    cout << "Enter amount: ";
                    cin >> amt;
                    acc->spendMoney(amt); // POLYMORPHISM
                    break;

                case 3:
                    acc->showBalance();   // POLYMORPHISM
                    break;

                case 4:
                    dynamic_cast<Wallet*>(acc)->showHistory();
                    break;
            }
        } while (choice != 5);
    }

    ~User() {
        delete acc;
    }
};

int main() {
    string name;
    cout << "Enter user name: ";
    cin >> name;

    User u(name);
    u.menu();

    return 0;
}
