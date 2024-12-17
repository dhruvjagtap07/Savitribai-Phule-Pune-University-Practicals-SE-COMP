#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Write C++ program using STL for sorting and searching user defined records such as Item
// records (Item code, name, cost, quantity etc) using vector container.

class Item {
    public:
    char name[10];
    int qty;
    float cost;
    int code;

	Item () : name(""), qty(0), cost(0), code(0) {}

    bool operator == (const Item& i1) const {
        return code == i1.code;
    }

    bool operator < (const Item& i1) const {
        return code < i1.code;
    }
};

vector<Item> v;

void print (Item& i1);
void display ();
void insert ();
void search ();
void dlt ();

bool compare (const Item& i1, const Item& i2) {
    return i1.code < i2.code;
}

int main () {
    int choice;
    do {
        cout << "======= < MENU > =========" << endl;
        cout << "1) Insert." << endl;
        cout << "2) Display." << endl;
        cout << "3) Search." << endl;
        cout << "4) Sort." << endl;
        cout << "5) Delete." << endl;
        cout << "6) Exit." << endl;
        cout << "==========================" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                insert();
                break;
            
            case 2:
                display();
                break;
            
            case 3:
                search();
                break;
            
            case 4:
                sort(v.begin(), v.end(), compare);
                cout << "Sorted by code" << endl;
                display();
                break;
            
            case 5:
                dlt();
                break;

            case 6:
                exit(0);

            default:
                cout << "Enter a valid choice." << endl;
        }
    } while (choice != 7);
}

void insert () {
    Item i;

    cout << "Enter Item name: ";
    cin >> i.name;

    cout << "Enter Item Quantity: ";
    cin >> i.qty;

    cout << "Enter Item cost: ";
    cin >> i.cost;

    cout << "Enter Item Code: " ;
    cin >> i.code;

    v.push_back(i);
}

void display () {
    for_each(v.begin(), v.end(), print);
}

void print (Item& i1) {

    cout << "__________________________" << endl;
    cout << "\nItem name : " << i1.name << endl;
    cout << "Item Qty  : " << i1.qty << endl;
    cout << "Item cost : " << i1.cost << endl;
    cout << "Item code : " << i1.code << endl;
    // cout << "__________________________" << endl;
}

void search () {
    vector<Item> :: iterator p;

    Item i;

    cout << "Enter Item Code to search: ";
    cin >> i.code;

    p = find (v.begin(), v.end(), i);

    if (p == v.end()) {
        cout << "Item not found!" << endl;
    } else {
        cout << "Item Found." << endl;
	
    }
} 

void dlt () {
    vector<Item> :: iterator p;

    Item i;

    cout << "Enter Item code to delete: ";
    cin >> i.code;

    p = find(v.begin(), v.end(), i);

    if (p == v.end()) {
        cout << "Invlaid Item code; item with CODE: " << i.code << " not found." << endl;
    } else {
        v.erase (p);
        cout << "Item Deleted. " << endl;
    }
}