#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int rollNo;
    float marks;

    void inputDetails()
    {
        cout << "Enter Student Name: ";
        getline(cin >> ws, name);

        cout << "Enter Roll Number: ";
        cin >> rollNo;

        cout << "Enter Marks: ";
        cin >> marks;
    }

public:
    void displayDetails()
    {
        inputDetails();

        cout << "\n----- Student Details -----\n";
        cout << "Name : " << name << endl;
        cout << "Roll No. : " << rollNo << endl;
        cout << "Marks : " << marks << endl;
    }
};

int main()
{
    Student s;

    s.displayDetails();

    return 0;
}