#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class Student
{
    // private:
    int rollNo;
    char name[30];
    char division;
    char address[50];

public:
    void getData()
    {
        cout << "Enter Roll no.: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << "Enter Division: ";
        cin >> division;
        cout << "Enter Address: ";
        cin.ignore();
        cin.getline(address, 50);
    }

    void showData()
    {
        cout << "Roll No.: " << rollNo << endl;
        cout << "Name: " << name << endl;
        cout << "Division: " << division << endl;
        cout << "Address: " << address << endl;
    }

    int getRollNo()
    {
        return rollNo;
    }
};

class FileHandler
{
    fstream file;

public:
    void addStudent()
    {
        Student s;
        file.open("Student.dat", ios::binary | ios::app);
        s.getData();
        file.write((char *)&s, sizeof(s));
        file.close();
    }

    void displayAll()
    {
        Student s;
        file.open("Student.dat", ios::binary | ios::in);
        if (!file)
        {
            cout << "\nFile not found!" << endl;
            return;
        }
        cout << "\nAll Students Data: " << endl;
        while (file.read((char *)&s, sizeof(s)))
        {
            s.showData();
            cout << endl;
        }

        file.close();
    }

    void searchStudent(int roll)
    {
        Student s;
        bool found = false;

        file.open("Student.dat", ios::binary | ios::in);
        while (file.read((char *)&s, sizeof(s)))
        {
            if (s.getRollNo() == roll)
            {
                found = true;
                s.showData();
                break;
            }
        }
        file.close();
        if (!found)
        {
            cout << "\nStudent with Roll No. " << roll << " not Found!" << endl;
        }
    }

    void deleteStudent(int roll)
    {
        Student s;
        ifstream inFile("Student.dat", ios::binary);
        ofstream outFile("Temp.dat", ios::binary);
        bool found = false;

        while (inFile.read((char *)&s, sizeof(s)))
        {
            if (s.getRollNo() == roll)
            {
                found = true;
                continue;
            }
            outFile.write((char *)&s, sizeof(s));
        }

        inFile.close();
        outFile.close();
        remove("Student.dat");
        rename("Temp.dat", "Student.dat");

        if (found)
            cout << "\nRecord deleted successfully.";
        else
            cout << "\nRecord not found.";
    }
};

int main()
{
    FileHandler fh;
    int choice, roll;

    do
    {
        cout << "\n1. Add Student\n2. Display All Students\n3. Search Student\n4. Delete Student\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            fh.addStudent();
            break;
        case 2:
            fh.displayAll();
            break;
        case 3:
            cout << "Enter Roll No. to search: ";
            cin >> roll;
            fh.searchStudent(roll);
            break;
        case 4:
            cout << "Enter Roll No. to delete: ";
            cin >> roll;
            fh.deleteStudent(roll);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}