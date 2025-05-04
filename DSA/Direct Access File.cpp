// Implementation of a direct access file -Insertion and deletion of a record from a direct
// access file

#include <iostream>
#include <fstream>
using namespace std;

const int TABLE_SIZE = 10;

class Student
{
public:
    int rollNo;
    char name[30];
    bool isDeleted;

    Student()
    {
        rollNo = -1;
        isDeleted = false;
    }

    void getData()
    {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 30);
        isDeleted = false;
    }

    void showData() const
    {
        if (!isDeleted && rollNo != -1)
        {
            cout << "Roll No: " << rollNo << ", Name: " << name;
        }
    }
};

// Hash function
int hashFunction(int rollNo)
{
    return rollNo % TABLE_SIZE;
}

void insertRecord()
{
    fstream file("student.dat", ios::in | ios::out | ios::binary);

    if (!file)
    {
        // Create and initialize file
        Student empty;
        file.open("student.dat", ios::out | ios::binary);
        for (int i = 0; i < TABLE_SIZE; ++i)
            file.write((char *)&empty, sizeof(Student));
        file.close();
        file.open("student.dat", ios::in | ios::out | ios::binary);
    }

    Student s;
    s.getData();
    int pos = hashFunction(s.rollNo);

    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        int index = (pos + i) % TABLE_SIZE;
        file.seekg(index * sizeof(Student));
        Student temp;
        file.read((char *)&temp, sizeof(Student));

        if (temp.rollNo == -1 || temp.isDeleted)
        {
            file.seekp(index * sizeof(Student));
            file.write((char *)&s, sizeof(Student));
            cout << "Record inserted.\n";
            file.close();
            return;
        }
    }

    cout << "Hash table is full.\n";
    file.close();
}

void deleteRecord(int rollNo)
{
    fstream file("student.dat", ios::in | ios::out | ios::binary);
    if (!file)
    {
        cout << "File not found.\n";
        return;
    }

    int pos = hashFunction(rollNo);
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        int index = (pos + i) % TABLE_SIZE;
        file.seekg(index * sizeof(Student));
        Student s;
        file.read((char *)&s, sizeof(Student));

        if (s.rollNo == rollNo && !s.isDeleted)
        {
            s.isDeleted = true;
            file.seekp(index * sizeof(Student));
            file.write((char *)&s, sizeof(Student));
            cout << "Record deleted.\n";
            file.close();
            return;
        }
    }

    cout << "Record not found.\n";
    file.close();
}

void displayRecords()
{
    ifstream file("student.dat", ios::binary);
    if (!file)
    {
        cout << "No data file found.\n";
        return;
    }

    Student s;
    cout << "\nAll records:\n";
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        file.read((char *)&s, sizeof(Student));
        cout << "[" << i << "] ";
        s.showData();
        cout << endl;
    }

    file.close();
}

int main()
{
    int choice, rollNo;
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Insert Record\n";
        cout << "2. Delete Record\n";
        cout << "3. Display All Records\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            insertRecord();
            break;
        case 2:
            cout << "Enter roll number to delete: ";
            cin >> rollNo;
            deleteRecord(rollNo);
            break;
        case 3:
            displayRecords();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 4);

    return 0;
}
