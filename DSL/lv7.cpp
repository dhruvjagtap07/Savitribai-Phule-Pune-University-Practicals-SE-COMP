// LV Assignment 7
// A double-ended queue (deque) is a linear list in which additions 
// and deletions may be made at either end. Obtain a data representation 
// mapping a deque into a linked list. Write C++ program to simulate deque 
// with functions to add and delete elements from either end of the deque.

#include <iostream>

using namespace std;

#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* prev;

    node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

class deque {
private:
    node* front;
    node* rear;

public:
    deque() : front(nullptr), rear(nullptr) {}

    void insertAtRear() {
        int value;
        cout << "Enter value to add at rear: ";
        cin >> value;

        node* newNode = new node(value);

        if (front == nullptr) { // If the deque is empty
            front = rear = newNode;
        } else {
            newNode->prev = rear; // Link newNode to the current rear
            rear->next = newNode; // Link current rear to newNode
            rear = newNode;       // Update rear
        }
        cout << "Added: " << value << " at the rear." << endl;
    }

    void insertAtFront() {
        int value;
        cout << "Enter value to add at front: ";
        cin >> value;

        node* newNode = new node(value);

        if (front == nullptr) { // If the deque is empty
            front = rear = newNode;
        } else {
            newNode->next = front; // Link newNode to the current front
            front->prev = newNode; // Link current front to newNode
            front = newNode;       // Update front
        }
        cout << "Added: " << value << " at the front." << endl;
    }

    void deleteAtRear() {
        if (front == nullptr) {
            cout << "Deque is empty, cannot delete from rear." << endl;
            return;
        }

        node* temp = rear;
        cout << "Deleted " << rear->data << " from the rear." << endl;

        if (front == rear) { // If there's only one element
            front = rear = nullptr;
        } else {
            rear = rear->prev; // Update rear to the previous node
            rear->next = nullptr;
        }

        delete temp;
    }

    void deleteAtFront() {
        if (front == nullptr) {
            cout << "Deque is empty, cannot delete from front." << endl;
            return;
        }

        node* temp = front;
        cout << "Deleted " << front->data << " from the front." << endl;

        if (front == rear) { // If there's only one element
            front = rear = nullptr;
        } else {
            front = front->next; // Update front to the next node
            front->prev = nullptr;
        }

        delete temp;
    }

    void display() {
        if (front == nullptr) {
            cout << "Deque is empty, nothing to display." << endl;
            return;
        }

        cout << "Deque: ";
        node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    deque dq;
    int choice;

    while (true) {
        cout << "\n===== Deque Operations =====\n";
        cout << "1. Add Front\n";
        cout << "2. Add Rear\n";
        cout << "3. Delete Front\n";
        cout << "4. Delete Rear\n";
        cout << "5. Display Deque\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            dq.insertAtFront();
            break;
        case 2:
            dq.insertAtRear();
            break;
        case 3:
            dq.deleteAtFront();
            break;
        case 4:
            dq.deleteAtRear();
            break;
        case 5:
            dq.display();
            break;
        case 6:
            cout << "Exiting... Thank you!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
