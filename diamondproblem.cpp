#include <iostream>
using namespace std;

// Base class
class Animal {
public:
    void eat() {
        cout << "Animal is eating" << endl;
    }
};

// Mammal inherits from Animal
class Mammal : virtual public Animal { };

// Bird inherits from Animal
class Bird :  virtual public Animal { };

// Bat inherits from both Mammal and Bird
class Bat : public Mammal, public Bird { };

int main() {
    Bat b;
    b.eat();   // ❌ ERROR: Ambiguous
    return 0;
}
