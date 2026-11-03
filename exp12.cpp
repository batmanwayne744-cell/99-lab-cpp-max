#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <stdexcept>
using namespace std;

const int SIZE = 60;
const int MAX_MEMBERS = 180;

// Safe integer input
int readInt(const string& prompt, int low, int high) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value && value >= low && value <= high) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        if (cin.eof()) throw runtime_error("Input ended");
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid number. Try again.\n";
    }
}

// Date class
class Date {
public:
    int day, month, year;

    Date(int d = 0, int m = 0, int y = 0)
        : day(d), month(m), year(y) {}

    static bool leap(int y) {
        return y % 400 == 0 ||
               (y % 4 == 0 && y % 100 != 0);
    }

    bool valid() const {
        if (year < 1 || year > 9999 ||
            month < 1 || month > 12)
            return false;

        int days[] = {
            31,28,31,30,31,30,31,31,30,31,30,31
        };

        if (leap(year)) days[1] = 29;

        return day >= 1 && day <= days[month - 1];
    }

    long toDays() const {
        int y = year - 1;
        long total = 365L * y + y / 4 - y / 100 + y / 400;

        int days[] = {
            31,28,31,30,31,30,31,31,30,31,30,31
        };

        if (leap(year)) days[1] = 29;

        for (int m = 1; m < month; ++m)
            total += days[m - 1];

        return total + day;
    }

    // Operator overloading
    bool operator<(const Date& other) const {
        return toDays() < other.toDays();
    }

    void show() const {
        cout << day << "/" << month << "/" << year;
    }
};

// Input date
Date inputDate() {
    while (true) {
        int d = readInt("Enter Day: ", 1, 31);
        int m = readInt("Enter Month: ", 1, 12);
        int y = readInt("Enter Year: ", 1, 9999);

        Date date(d, m, y);

        if (date.valid())
            return date;

        cout << "Invalid calendar date. Please enter again.\n";
    }
}

// Inheritance and virtual function
class FinePolicy {
public:
    virtual double fine(int days) const = 0;
    virtual ~FinePolicy() {}
};

class StandardFine : public FinePolicy {
public:
    double fine(int days) const override {
        return days * 10.0;
    }
};

// Library class
class Library {
private:
    int type, bookNumber;
    char status;
    string memberName;
    Date issueDate, returnDate;
    double charge, bill;

public:
    // Constructor
    Library()
        : type(0), bookNumber(0), status('A'),
          charge(0), bill(0) {}

    void setBook(int t, int number, double rate) {
        type = t;
        bookNumber = number;
        charge = rate;
        status = 'A';
    }

    int getType() const {
        return type;
    }

    int getNumber() const {
        return bookNumber;
    }

    char getStatus() const {
        return status;
    }

    double getCharge() const {
        return charge;
    }

    const string& getName() const {
        return memberName;
    }

    Date getIssueDate() const {
        return issueDate;
    }

    Date getReturnDate() const {
        return returnDate;
    }

    double getBill() const {
        return bill;
    }

    void issue() {
        status = 'I';
    }

    void release() {
        status = 'A';
    }

    void setMember(int t, int number,
                   const string& name,
                   Date date, double rate) {
        type = t;
        bookNumber = number;
        memberName = name;
        issueDate = date;
        returnDate = Date();
        charge = rate;
        bill = 0;
        status = 'I';
    }

    void finish(Date date, double total) {
        returnDate = date;
        bill = total;
        status = 'A';
    }

    bool returned() const {
        return returnDate.valid();
    }
};

// Library Management class
class LibraryManagement {
private:
    Library Members[MAX_MEMBERS];

    Library fiction_Book[SIZE];
    Library science_Book[SIZE];
    Library reference_Book[SIZE];

    int n;
    StandardFine finePolicy;

    Library& selectedBook(int type, int number) {
        if (type == 1)
            return fiction_Book[number - 1];

        if (type == 2)
            return science_Book[number - 1];

        return reference_Book[number - 1];
    }

    // Find member by name
    int findMember(const string& name, bool activeOnly) const {
        for (int i = n - 1; i >= 0; --i) {
            if (Members[i].getName() == name &&
                (!activeOnly || !Members[i].returned())) {
                return i;
            }
        }

        return -1;
    }

    // Function overloading
    int calculateDays(long inDays, long outDays) const {
        return static_cast<int>(outDays - inDays);
    }

    int calculateDays(const Date& inDate,
                      const Date& outDate) const {
        return calculateDays(
            inDate.toDays(),
            outDate.toDays()
        );
    }

public:
    // Constructor
    LibraryManagement() : n(0) {
        book_assigning();
    }

    // Assign 180 books
    void book_assigning() {
        for (int i = 0; i < SIZE; ++i) {
            fiction_Book[i].setBook(1, i + 1, 0);
            science_Book[i].setBook(2, i + 1, 0);
            reference_Book[i].setBook(3, i + 1, 0);
        }
    }

    // Issue book
    void member_Input() {
        cout << "\n<------------Book Issue------------>\n";

        if (n >= MAX_MEMBERS) {
            cout << "Member record limit reached (180).\n";
            return;
        }

        int type = readInt(
            "Enter Type of book (1.Fiction 2.Science 3.Reference): ",
            1, 3
        );

        string name;

        cout << "Enter Member name: ";
        getline(cin, name);

        if (name.find_first_not_of(" \t") == string::npos) {
            cout << "Member name cannot be empty.\n";
            return;
        }

        int number;

        while (true) {
            number = readInt(
                "Enter Book Number For Issue (1-60): ",
                1, 60
            );

            if (selectedBook(type, number).getStatus() == 'A')
                break;

            cout << "Book is already issued! "
                 << "Choose another book.\n";
        }

        Library& book = selectedBook(type, number);

        cout << "Fine per day: Rs.10.00"
             << "\nEnter Issue Date\n";

        Date date = inputDate();

        Members[n].setMember(
            type, number, name, date, book.getCharge()
        );

        book.issue();
        ++n;

        cout << "Book type-" << type
             << " number " << number << " - I\n";

        cout << "<------------Issued successfully------------>\n";
    }

    // Return book
    void return_Book() {
        cout << "\n<------------Book Return------------>\n";

        if (n == 0) {
            cout << "Member records are zero\n";
            return;
        }

        string name;
        int index;

        while (true) {
            cout << "Enter Member Name (or return): ";
            getline(cin, name);

            if (name == "return")
                return;

            index = findMember(name, true);

            if (index >= 0)
                break;

            cout << "Member not found among issued books!\n";
        }

        Library& member = Members[index];

        cout << "Book number: "
             << member.getNumber() << '\n';

        cout << "Enter Return Date\n";

        Date out = inputDate();

        // Operator overloading
        if (!(member.getIssueDate() < out)) {
            throw invalid_argument(
                "Return Date must be after Issue Date."
            );
        }

        int days = calculateDays(
            member.getIssueDate(), out
        );

        // Seven days allowed without fine
        int lateDays = days > 7 ? days - 7 : 0;

        // Runtime polymorphism
        const FinePolicy& policy = finePolicy;

        double total = policy.fine(lateDays);

        member.finish(out, total);

        selectedBook(
            member.getType(),
            member.getNumber()
        ).release();

        cout << fixed << setprecision(2)
             << "Total Days: " << days
             << "\nLate Days: " << lateDays
             << "\nFine: Rs." << total
             << "\nBook is Now Available\n"
             << "<------Book Returned Successfully------>\n";
    }

    // Display issued books
    void display_Issued_Book() const {
        cout << "\n<------------Issued Books------------>\n";

        cout << "Fiction - Issued Books: ";

        bool found = false;

        for (int i = 0; i < SIZE; ++i) {
            if (fiction_Book[i].getStatus() == 'I') {
                cout << fiction_Book[i].getNumber() << ' ';
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << "\nScience - Issued Books: ";

        found = false;

        for (int i = 0; i < SIZE; ++i) {
            if (science_Book[i].getStatus() == 'I') {
                cout << science_Book[i].getNumber() << ' ';
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << "\nReference - Issued Books: ";

        found = false;

        for (int i = 0; i < SIZE; ++i) {
            if (reference_Book[i].getStatus() == 'I') {
                cout << reference_Book[i].getNumber() << ' ';
                found = true;
            }
        }

        if (!found)
            cout << "None";

        cout << "\n";
    }

    // Display library charges
    void charges() const {
        cout << "\n<------------Library Charges------------>\n";

        cout << fixed << setprecision(2)
             << "Fiction book fine per day: Rs.10.00"
             << "\nScience book fine per day: Rs.10.00"
             << "\nReference book fine per day: Rs.10.00"
             << "\nAllowed borrowing period: 7 days\n";
    }

    // Member information
    void member_info() const {
        cout << "\n<------------Member Information------------>\n";

        if (n == 0) {
            cout << "No member records.\n";
            return;
        }

        string name;
        int index;

        while (true) {
            cout << "Enter Member Name (or return): ";
            getline(cin, name);

            if (name == "return")
                return;

            index = findMember(name, false);

            if (index >= 0)
                break;

            cout << "Member not found!\n";
        }

        const Library& member = Members[index];

        cout << "Book number: "
             << member.getNumber()
             << "\nType: "
             << member.getType()
             << "\nIssue date: ";

        member.getIssueDate().show();

        if (member.returned()) {
            cout << "\nReturn date: ";
            member.getReturnDate().show();

            cout << "\nFine: Rs."
                 << fixed << setprecision(2)
                 << member.getBill();
        }
        else {
            cout << "\nMember hasn't returned the book yet."
                 << "\nFine calculation is pending.";
        }

        cout << "\n";
    }
};

// Main function
int main() {
    LibraryManagement library;

    try {
        while (true) {
            cout << "\n<------------Library Management------------>\n"
                 << "1.Issue Book.\n"
                 << "2.Return Book.\n"
                 << "3.Issued Books.\n"
                 << "4.Library Charges.\n"
                 << "5.Member Info.\n"
                 << "6.Exit\n";

            int choice = readInt("Enter choice: ", 1, 6);

            if (choice == 6) {
                cout << "<------------Exit successfully------------>\n";
                break;
            }

            try {
                switch (choice) {
                    case 1:
                        library.member_Input();
                        break;

                    case 2:
                        library.return_Book();
                        break;

                    case 3:
                        library.display_Issued_Book();
                        break;

                    case 4:
                        library.charges();
                        break;

                    case 5:
                        library.member_info();
                        break;
                }
            }
            catch (const invalid_argument& e) {
                cout << "Error: " << e.what() << '\n';
            }
        }
    }
    catch (const exception& e) {
        cout << "Program stopped: "
             << e.what() << '\n';
    }

    return 0;
}
