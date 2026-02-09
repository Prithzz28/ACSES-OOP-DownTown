#include <iostream>
using namespace std;

// Parent class
class Parent {
public:
    void showParent() {
        cout << "This is the Parent class" << endl;
    }
};

// Child class inheriting from Parent
class Child : public Parent {
public:
    void showChild() {
        cout << "This is the Child class" << endl;
    }
};

int main() {
    Child c;
    c.showParent();  // Inherited method
    c.showChild();   // Child's own method
    return 0;
}
