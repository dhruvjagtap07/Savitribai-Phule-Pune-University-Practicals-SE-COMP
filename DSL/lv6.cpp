// Pizza parlor accepting maximum M orders. Orders are served in 
// first come first served basis. Order once placed cannot be 
// cancelled. Write C++ program to simulate the system using 
// circular queue using array.
#include <iostream>

using namespace std;


class Queue {
    private:
    int front;
    int rear;
    int size = 5;
    int* arr;

    public:
    Queue (int s = 5) {
        front = -1;
        rear = -1;
        size = s;
        arr = new int[size];
    }

    void acceptOrder (int item) {
        if (front == (rear + 1) % size) {
            cout << "Cafe is full, please wait." << endl;
            return;
        } else {
            if (front == - 1) {
                front = rear = 0;
            } else {
                rear = (rear + 1) % size;
            }
            arr[rear] = item;

            cout << "Order accepted: " << item << endl;
        }
    }

    int serveOrder () {
        if (front == -1) {
            cout << "No orders in cafe, cafe is empty." << endl;
            return -1;
        } 

        int val = arr[front];
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }

        return val;
    }

    void displayOrder () {
        if (front == -1) {
            cout << "No orders in cafe, cafe is empty." << endl;
            return;
        }
        cout << "Orders in cafe: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~Queue() {
        delete[] arr;
    }
};

int main() {
    
    int choice, order, n;

    cout << "\n======== Pizza Parlor Menu =========\n";
    cout << "Enter maximum capacity of order: " ;
    cin >> n;

    Queue q(n);

    while (true) {
        
        cout << "\n1. Accept Order" << endl;
        cout << "2. Serve Order" << endl;
        cout << "3. Display Orders" << endl;;
        cout << "4. Exit" << endl;;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the order number to accept: ";
                cin >> order;
                q.acceptOrder(order);
                break;
            case 2:
                order = q.serveOrder();
                if (order != -1)
                    cout << "Order served: " << order << endl;
                break;
            case 3:
                q.displayOrder();
                break;
            case 4:
                cout << "Exiting... Thank you!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}