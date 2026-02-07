#include <iostream>
using namespace std;

// Function to calculate total marks using pointer
void calculateTotal(int marks[], int n, int *total)
{
    *total = 0;

    for (int i = 0; i < n; i++)
    {
        *total = *total + marks[i];
    }
}

int main()
{
    int choice;
    char repeat;

    int total = -1;   // -1 means total not calculated yet

    do
    {
        cout << "\n===== Student Utility Program =====\n";
        cout << "1. Calculate total marks\n";
        cout << "2. Check pass or fail\n";
        cout << "3. Display grade\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int marks[5];

            cout << "Enter marks of 5 subjects:\n";
            for (int i = 0; i < 5; i++)
            {
                cin >> marks[i];
            }

            calculateTotal(marks, 5, &total);   // pointer used
            cout << "Total Marks = " << total << endl;
            break;
        }

        case 2:
        {
            if (total == -1)
            {
                cout << "Please calculate total marks first!\n";
                break;
            }

            if (total >= 200)
                cout << "Result: PASS\n";
            else
                cout << "Result: FAIL\n";

            break;
        }

        case 3:
        {
            if (total == -1)
            {
                cout << "Please calculate total marks first!\n";
                break;
            }

            int percentage = total / 5;

            if (percentage >= 90)
                cout << "Grade: A+\n";
            else if (percentage >= 75)
                cout << "Grade: A\n";
            else if (percentage >= 60)
                cout << "Grade: B\n";
            else
                cout << "Grade: C\n";

            break;
        }

        case 4:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}
