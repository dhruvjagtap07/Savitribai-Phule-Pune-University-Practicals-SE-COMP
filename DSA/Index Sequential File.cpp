// Company maintains employee information as employee ID, name, designation and
// salary. Allow user to add, delete information of employee. Display information of
// particular employee. If employee does not exist an appropriate message is displayed. If
// it is, then the system displays the employee details. Use index sequential file to maintain
// the data.

#include <iostream>
#include <fstream>
#include <map>
#include <cstring>

using namespace std;

class Employee
{
    int empID;
    char name[30];
    char designation[30];
    float salary;

public:
    void getData()
    {
        cout << "Enter Employee ID: ";
        cin >> empID;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 30);
        cout << "Enter Designation: ";
        cin.getline(designation, 30);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void showData()
    {
        cout << "Employee ID: " << empID << endl;
        cout << "Name: " << name << endl;
        cout << "Designation: " << designation << endl;
        cout << "Salary: " << salary << endl;
    }

    int getEmpID()
    {
        return empID;
    }
};

class IndexSequential
{
    fstream dataFile;
    map<int, streampos> index;

    void buildIndex()
    {
        index.clear();
        dataFile.open("Employee.dat", ios::in | ios::binary);
        if (!dataFile)
            return;

        Employee e;
        streampos pos;

        while (!dataFile.eof())
        {
            pos = dataFile.tellg();
            if (dataFile.read((char *)&e, sizeof(e)))
            {
                index[e.getEmpID()] = pos;
            }
        }
        dataFile.close();
    }

public:
    IndexSequential()
    {
        buildIndex();
    }

    void addEmployee()
    {
        Employee e;
        e.getData();

        dataFile.open("Employee.dat", ios::app | ios::binary);
        streampos pos = dataFile.tellp();
        dataFile.write((char *)&e, sizeof(e));
        dataFile.close();

        index[e.getEmpID()] = pos;
    }

    void displayEmployee(int empID)
    {
        if (index.find(empID) == index.end())
        {
            cout << "\nEmployee with ID " << empID << " not found!\n";
            return;
        }

        dataFile.open("Employee.dat", ios::in | ios::binary);
        dataFile.seekg(index[empID]);
        Employee e;
        dataFile.read((char *)&e, sizeof(e));
        dataFile.close();

        e.showData();
    }

    void displayAll()
    {
        Employee e;
        dataFile.open("Employee.dat", ios::in | ios::binary);
        if (!dataFile)
        {
            cout << "\nFile not found!" << endl;
            return;
        }
        cout << "\nAll Employees Data:\n";
        while (dataFile.read((char *)&e, sizeof(e)))
        {
            e.showData();
            cout << endl;
        }
        dataFile.close();
    }

    void deleteEmployee(int empID)
    {
        if (index.find(empID) == index.end())
        {
            cout << "\nEmployee not found!" << endl;
            return;
        }

        Employee e;
        ifstream inFile("Employee.dat", ios::binary);
        ofstream outFile("Temp.dat", ios::binary);

        while (inFile.read((char *)&e, sizeof(e)))
        {
            if (e.getEmpID() != empID)
                outFile.write((char *)&e, sizeof(e));
        }

        inFile.close();
        outFile.close();

        remove("Employee.dat");
        rename("Temp.dat", "Employee.dat");

        cout << "\nEmployee deleted successfully!" << endl;

        buildIndex(); // Rebuild index after deletion
    }
};

int main()
{
    IndexSequential is;
    int choice, empID;

    do
    {
        cout << "\n1. Add Employee\n2. Display All Employees\n3. Display Particular Employee\n4. Delete Employee\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            is.addEmployee();
            break;
        case 2:
            is.displayAll();
            break;
        case 3:
            cout << "Enter Employee ID to search: ";
            cin >> empID;
            is.displayEmployee(empID);
            break;
        case 4:
            cout << "Enter Employee ID to delete: ";
            cin >> empID;
            is.deleteEmployee(empID);
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}
