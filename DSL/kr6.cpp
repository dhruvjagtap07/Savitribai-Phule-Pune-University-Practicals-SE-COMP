// KR Assigment 6

// Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set
// B of students like butterscotch ice-cream. Write C++ program to store two sets using
// linked list. compute and display-
// a) Set of students who like both vanilla and butterscotch
// b) Set of students who like either vanilla or butterscotch or not both
// c) Number of students who like neither vanilla nor butterscotch

#include <iostream> 

using namespace std;

struct node {
    int data;
    node* next;

    node (int value) {
        data = value;
        next = nullptr;
    }
};

class sy {
    private:
    node* head;

    public:
    sy () : head (nullptr) {}

    void insert (int value) {
        node* newNode = new node(value);

        if (head == nullptr) {
            head = newNode;
        } else {
            node* temp = head;
            while (temp -> next != nullptr) {
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }

    void display () {
        node* temp = head;

        while (temp != nullptr) {
            cout << temp -> data << " ";
            temp = temp -> next;
        }
        cout << endl;
    }

    bool contains (int value) {
        node* temp = head;
        while (temp) {
            if (temp -> data == value) return true;
            temp = temp -> next;
        }
        return false;
    }

    node* getHead () {
        return head;
    }

    friend void findIntersetion(sy& setA, sy& setB, sy& result);

    friend void symDifference(sy& setA, sy& setB, sy& result);

    friend int findComplement(sy& universalSet, sy& setA, sy& setB);
};

void findIntersection(sy& setA, sy& setB, sy& result) {
    node* tempA = setA.getHead();

    while(tempA) {
        if (setB.contains(tempA -> data)) {
            result.insert(tempA -> data);
        }
        tempA = tempA -> next;
    }
}

void symDifference(sy& setA, sy& setB, sy& result) {
    node* tempA = setA.getHead();
    node* tempB = setB.getHead();

    while (tempA) {
        if (!setB.contains(tempA -> data)) {
            result.insert(tempA -> data);
        }
        tempA = tempA -> next;
    }

    while (tempB) {
        if (!setA.contains(tempB -> data)) {
            result.insert(tempB -> data);
        }
        tempB = tempB -> next;
    }
}

int findComplement(sy& universalSet, sy& setA, sy& setB) {
    int cnt = 0;

    node* temp = universalSet.getHead();

    while (temp) {
        if (!setA.contains(temp -> data) && !setB.contains(temp -> data)) {
            cnt++;
        }
        temp = temp -> next;
    }

    return cnt;
}

int main () {
    sy s, universalSet, vanillaSet, butterscotchSet, bothSet, eitherSet;
    int totalStudents, n, value;

    cout << "Enter the total number of students in the class: ";
    cin >> totalStudents;

    // Build universal set of all students (1 to totalStudents)
    for (int i = 1; i <= totalStudents; ++i) {
        universalSet.insert(i);
    }

    cout << "Enter the number of students who like Vanilla ice cream: ";
    cin >> n;
    cout << "Enter their roll numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        vanillaSet.insert(value);
    }

    cout << "Enter the number of students who like Butterscotch ice cream: ";
    cin >> n;
    cout << "Enter their roll numbers: ";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        butterscotchSet.insert(value);
    }

    findIntersection(vanillaSet, butterscotchSet, bothSet);

    // Find symmetric difference (students who like either but not both)
    symDifference(vanillaSet, butterscotchSet, eitherSet);

    // Find complement (students who like neither)
    int neitherCount = findComplement(universalSet, vanillaSet, butterscotchSet);
    
    cout << "\nStudents who like both Vanilla and Butterscotch: ";
    bothSet.display();

    cout << "\nStudents who like either Vanilla or Butterscotch but not both: ";
    eitherSet.display();

    cout << "\nNumber of students who like neither Vanilla nor Butterscotch: " << neitherCount << endl;

    return 0;
}
