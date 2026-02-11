#include<bits/stdc++.h>
using namespace std;

class StuReg{
    // Data members
    private:
        int rno; //Accessible within class only.
    public:
        string name; //Accessible throughout the program.
    protected:
        int fees;
    
    public:
    // Member Functions.

    StuReg() //Default Constructor
    {
        rno=0;
        name="null";
        fees=0;
    }
    StuReg(int rno, string s,int f) //Parameterized Constructor
    {
        this->rno=rno;
        name=s;
        fees=f;
    }
    void setData() //Setter method
    {
        cout<<"Enter Roll No: ";
        cin>>rno;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter fees paid: ";
        cin>>fees;
    }
    void display() //Getter method
    {
        cout<<"Roll No: "<<rno<<"\nName: "<<name<<"\nFees Paid: "<<fees;
    }

    ~StuReg(){
        cout<<"\nDestructor called\n";
    }
};

class EditReg: public StuReg{
    public:

    /*void EditRno()
    {
        cin>>rno; //check the error summary
    }*/
    void EditName()
    {
        cout<<"Enter Name: ";
        cin>>name;
    }
    void EditFees()
    {
        cout<<"Enter fees: "; //Accessible in child class
        cin>>fees;
    }
};

int main()
{
    /*//first execute this.
    StuReg obj1=StuReg();
    obj1.display();

    obj1=StuReg(27,"OOP DownTown",0);
    obj1.display();*/

    //later execute this.
    EditReg obj; //Object of child class will have all attributes and methods of parent class.
    obj.setData();
    obj.display();
    
    /*obj.rno=15;  //private variable not accessible outside class.
    obj.fees=100000; //protected member not accessible ouside parent & child class.*/
    
    obj.EditName();
    obj.display();

    obj.EditFees();
    obj.display();
}

