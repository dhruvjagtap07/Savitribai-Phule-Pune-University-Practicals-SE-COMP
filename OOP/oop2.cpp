#include <iostream>
#include <string.h>
#include <limits>

using namespace std;

// Develop a program in C++ to create a database of student’s information system containing the
// following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact
// address, Telephone number, Driving license no. and other. Construct the database with
// suitable member functions. Make use of constructor, default constructor, copy constructor,
// destructor, static member functions, friend class, this pointer, inline code and dynamic
// memory allocation operators-new and delete as well as exception handling.

class info {
    private:
    string nm, dr_lic, cl, dob;
    char* roll = new char[5];
    char* div = new char[1];
    char* bdgp = new char[3];

    public:
    info () {
        nm = "";
        dr_lic = "" ;
        cl = "";
        dob = "";
        roll = new char[5]{'\0'};
        div = new char[1]{'\0'};
        bdgp = new char[3]{'\0'};
    }

    info (const info& obj) {
        nm = obj.nm;
        dr_lic = obj.dr_lic;
        cl = obj.dr_lic;
        dob = obj.dob;
        roll = obj.roll;
        div = new char[strlen(obj.div) + 1];
        strcpy(div, obj.div);
        bdgp = new char [strlen(obj.bdgp) + 1];
        strcpy(bdgp, obj.bdgp);
    }

    ~info () {
        delete bdgp;
        delete div;
        delete roll;
    }
    
    friend class addInfo;

    inline void displayMessage() const {
        cout << "Welcome to the Student Information System(SIS)." << endl;
    }

    void inputInfo () {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n\n________STUDENT DATABASE________\n\n" << endl;
        cout << "Student name: ";
        getline(cin, nm);

        cout << "Class: ";
        getline(cin, cl);

        cout << "Division: ";
        delete div;
        div = new char[10];
        cin >> div;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Roll no. : ";
        delete roll;
        roll = new char[5];
        cin >> roll;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Date of Birth in format (dd/mm/yyyy): ";
        getline(cin, dob);

        cout << "Blood Group (A+, A-, B+, B-, AB+, AB-, O+, O-): ";
        delete bdgp;
        bdgp = new char[10];
        cin >> bdgp;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        cout << "Driving license: ";
        getline(cin , dr_lic);
    }
};

class addInfo {
    private:
    long ctNum;

    public:

    void getInfo () {
        while (true) {
            cout << "Contact Number: ";
            cin >> ctNum;

            if (cin.fail() || ctNum < 1000000000 || ctNum > 9999999999) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout <<"Invalid contact number, Enter vaild 10-digit number." << endl;
            } else {
                break;
            }
        }
    }

    string getRoll (const info& obj) {
        return obj.roll;
    }

    void showInfo (const info& obj) {
        cout << "Student Name   : " << obj.nm << endl;
        cout << "Class          : " << obj.cl << endl;
        cout << "Div            : " << obj.div << endl;
        cout << "Roll No.       : " << obj.roll << endl;
        cout << "Blood Group    : " << obj.bdgp << endl;
        cout << "Driving License: " << obj.dr_lic << endl;
        cout << "Contact no.    : " << ctNum << endl;
        cout << "====================================== " << endl;
    }
};

int main () {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    info* students = new info[n];
    addInfo* contacts = new addInfo[n];

    for (int i = 0; i < n; i++) {
        cout << "===============================================" << endl;
        cout << "Enter details for student: " << i + 1 << endl;
        students[i].inputInfo();
        contacts[i].getInfo();
    }

    cout << "\n_________STUDENT DATABASE ___________" << endl;
    cout << "=====================================" << endl;
    for (int i = 0; i < n; i++) {
        contacts[i].showInfo(students[i]);
    }

    while (true) {
        int choice, found = 0;
        string roll_no;
        cout << "Enter Student Roll Number to Get Info: ";
        getline(cin,roll_no);

        for (int i = 0; i < n; i++) {
            if (roll_no == contacts[i].getRoll(students[i])) {
                found = 1;
                contacts[i].showInfo(students[i]);
                break;
            }
        }

        if (!found) {
            cout << " Record Not Found." << endl;
        }
        cout << "Do you want to continue (Enter: 1 for Yes, 0 for No): ";
        cin >> choice;

        if (choice != 1) {
            break;
        }
    }
    delete[] students;
    delete[] contacts;

    cout << "\nEnding program..." << endl;
    return 0;
}