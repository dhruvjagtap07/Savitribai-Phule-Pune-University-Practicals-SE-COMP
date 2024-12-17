#include <iostream>
#include <vector>
#define SIZE 30

using namespace std;

// Write a function template for selection sort that inputs, sorts and outputs an integer array and
// a float array.

template <class T>
void sel(T A[], int n) {
    int min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (A[min] > A[j]) {
                min = j;
            }
        }
        T temp = A[i];
        A[i] = A[min];
        A[min] = temp; 
    }

    cout << "\nSorted array: ";
    for (int i = 0; i < n - 1; i++) {
        cout << A[i] << ", ";
    }
    cout << A[n - 1];
    cout << endl;
}

int main() {
    int choice;
    do {
        cout << "========== < MENU > ===========" << endl;
        cout << "1) Integer values." << endl;
        cout << "2) Float values." << endl;
        cout << "3) Exit. " << endl;
        cout << "=========== * * * =============" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "Enter the total numbers: ";
                cin >> n;
                int* A = new int[n];
                for (int i = 0; i < n; i++) {
                    cout << "Enter element (" << i + 1 << "): ";
                    cin >> A[i];
                }
                sel(A, n);
                delete[] A;
                break;
            }
            case 2: {
                int n;
                cout << "Enter the total numbers: ";
                cin >> n;
                float* B = new float[n];
                for (int i = 0; i < n; i++) {
                    cout << "Enter element (" << i + 1 << "): ";
                    cin >> B[i];
                }
                sel(B, n);
                delete[] B;
                break;
            }
            case 3:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Enter a valid choice." << endl;
        }
    } while (choice != 3);

    return 0;
}
