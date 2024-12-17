// Department of Computer Engineering has student's club named
// 'Pinnacle Club'. Students of Second, third and final year of
// department can be granted membership on request. Similarly one
// may cancel the membership of club. First node is reserved for
// president of club and last node is reserved for secretary of
// club. Write C++ program to maintain club member‘s information
// using singly linked list. Store student PRN and Name. Write
// functions to
// a) Add and delete the members as well as president or even
// secretary.
// b) Compute total number of members of club
// c) Display members
// d) Display list in reverse order using recursion
// e) Two linked lists exists for two divisions. Concatenate two
// lists

#include <iostream>
#include <string.h>
using namespace std;

struct Node {
    int prn;
    string name;
    Node* nxt;

    Node (int p, string s) : prn(p), name(s), nxt(nullptr) {}
};

class pnc {
    private:
    Node* head;

    public:

    pnc () : head(nullptr) {}

    void addMem(bool isPresident = false, bool isSecretary = false) {
        int p;
        string n;

        cout << "Enter PRN no. : ";
        cin >> p;
        cout << "Enter name: ";
        cin >> n;

        Node* newNode = new Node(p, n);

        if (isPresident) {
            newNode -> nxt = head;
            head = newNode;  
        }else if (isSecretary) {

            if (head == nullptr) {
                cout << "No president found! Add a president first." << endl;
                delete newNode;
                return;
            }

            Node* temp = head;

            while(temp -> nxt != nullptr) {
                temp = temp -> nxt;
            }
            temp -> nxt = newNode;
        }else {
            if (head == nullptr) {
                cout << "No president found! Add a president first." << endl;
                delete newNode;
                return;
            }

            Node* temp = head;
            while (temp -> nxt != nullptr && temp -> nxt -> nxt != nullptr) {
                temp = temp -> nxt;
            }
            newNode -> nxt = temp -> nxt;
            temp -> nxt = newNode;
        }
    }

    void deleteMem() {
        int p;
        cout << "Enter the PRN no. of a member to deleted: ";
        cin >> p;
        bool found = false;
        Node* temp = head;
        Node* prev = head;
        
        if (head == nullptr) {
            cout << "Club is Empty." << endl;
            return;
        }

        if (head -> prn == p) {
            found = true;
            head = head -> nxt;
            delete temp;
            cout << "President with PRN no.: " << p << " is removed." << endl;
            return;
        }
        
        while (temp != nullptr) {
            if (temp -> prn == p) {
                found = true;
                
                if (temp -> nxt == nullptr) {
                    if (prev == head) {
                        head -> nxt = nullptr;
                    } else {
                        prev -> nxt = nullptr;
                    }
                    cout << "Secretary with PRN no.: " << p << " is removed." << endl;
                } else {
                    prev -> nxt = temp -> nxt;
                    cout << "Member with PRN no.: " << p << " is removed." << endl;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp -> nxt;
        }

        if (!found) {
            cout << "Invalid PRN number or member is not present." << endl;
        }
    }

    void cntMem () {
        int cnt = 0;
        
        if (head == nullptr) {
            cout << "Club is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cnt++;
            temp = temp -> nxt;
        }

        cout << cnt << " members present in club including president and secretary." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "Club is empty." << endl;
            return;
        }

        // Print President (head of the list)
        cout << "\nPresident - PRN: " << head->prn << ", Name: " << head->name << endl;

        if (head->nxt == nullptr) {
            // Only the President exists, no other members
            cout << "Only president in the club." << endl;
            return;
        }

    // If there are members other than the President, display them
        cout << "\nMembers - " << endl;
        Node* temp = head->nxt;
        while (temp != nullptr && temp->nxt != nullptr) {
            cout << "\tPRN: " << temp->prn << ", Name: " << temp->name << endl;
            temp = temp->nxt;
        }

    // Finally, print the Secretary (last node)
        cout << "\nSecretary - PRN: " << temp->prn << ", Name: " << temp->name << endl;
    }

    void displayReverse(Node* current) {
        // Base case: if current is nullptr, we've reached the end of the list
        if (current == nullptr) {
            return;
        }
        // Recursive call to move to the nxt node
        displayReverse(current->nxt);

        // Print the current node after the recursive call (this prints nodes in reverse order)
        cout << "PRN: " << current->prn << ", Name: " << current->name << endl;
    }

    void dis() {
        if (head == nullptr) {
            cout << "Club is empty." << endl;
            return;
        }

        cout << "Reversed List (using recursion): " << endl;
        displayReverse(head);  // Start the recursion from the head
    }

    
    pnc concate(pnc& obja, pnc& objb) {
        // If the first club is empty, return the second club
        if (obja.head == nullptr) {
            cout << "First club is empty." << endl;
            return objb; // Return the second club, which is not empty
        }

        // If the second club is empty, return the first club
        if (objb.head == nullptr) {
            cout << "Second club is empty." << endl;
            return obja; // Return the first club, which is not empty
        }

        Node* temp = obja.head;
        while (temp->nxt != nullptr) {
            temp = temp->nxt;  // Move to the last node of the first list
        }

        // Link the last node of obja to the first node of objb
        temp->nxt = objb.head;

        // The modified obja now has both lists concatenated
        cout << "Clubs successfully concatenated." << endl;

        return obja;  // Return the concatenated club list
    }

};

int main () {
    pnc clubA, clubB;
    int n;

    // Add members to Club A
    cout << "Adding members to Club A:\n";
    cout << "Enter the no. of members: ";
    cin >> n;
    clubA.addMem(true); // President
    for (int i = 0; i < n -2; i ++) {
        clubA.addMem();
    }
    clubA.addMem(false, true);

    cout << "Adding members to Club B:\n";
    cout << "Enter the no. of members: ";
    cin >> n;
    clubB.addMem(true); // President
    for (int i = 0; i < n -2; i ++) {
        clubB.addMem();
    }
    clubB.addMem(false, true);

    clubA.display();
    clubB.display();

    clubA.deleteMem();
    clubA.display();
    clubA.deleteMem();
    clubA.display();
    clubA.deleteMem();
    clubA.display();
    return 0;
}
                    
