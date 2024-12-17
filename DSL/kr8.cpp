// KR Assignment 8

// Queues are frequently used in computer programming, and a typical example is the
// creation of a job queue by an operating system. If the operating system does not use
// priorities, then the jobs are processed in the order they enter the system. Write C++
// program for simulating job queue. Write functions to add job and delete job from queue

#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int size;
    int front;
    int rear;

public:
    // Constructor initializes the queue
    Queue(int n = 10) {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Function to add a job to the queue
    void push(int x) {
        if ((rear + 1) % size == front) { // Queue full condition
            cout << "Queue is full." << endl;
            return;
        } else if (front == -1) { // First element being inserted
            front = rear = 0;
        } else { // Regular insertion
            rear = (rear + 1) % size;
        }
        arr[rear] = x;
        cout << "Pushed " << x << " into the job queue." << endl;
    }

    // Function to remove a job from the queue
    void pop() {
        if (front == -1) { // Queue empty condition
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Popped " << arr[front] << " out of the queue." << endl;
        if (front == rear) { // Single element in queue
            front = rear = -1;
        } else { // Regular removal
            front = (front + 1) % size;
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Function to check if the queue is full
    bool isFull() {
        return (rear + 1) % size == front;
    }

    // Function to get the front element
    int numFront() {
        if (front == -1) {
            cout << "Queue is empty." << endl;
            return -1;
        } else {
            return arr[front];
        }
    }
};

int main() {
    Queue q;

    // Adding jobs to the queue
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Removing jobs from the queue
    q.pop();
    q.pop();

    // Checking if the queue is empty or full
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;

    // Displaying the front job
    cout << "Front job in the queue: " << q.numFront() << endl;

    return 0;
}
