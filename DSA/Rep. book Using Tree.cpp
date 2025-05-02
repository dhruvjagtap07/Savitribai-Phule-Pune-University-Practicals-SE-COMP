// DSA Practical: A book consists of chapters, chapters consist of sections and
// sections consist of subsections. Construct a tree and print the nodes. Find the
// time and space requirements of your method.

#include <iostream>
#include <string>

using namespace std;

struct Node
{
    int count;
    Node **child;
    string name;

    Node() : count(0), child(nullptr) {}
};

class Book
{
private:
    Node *root;

public:
    Book() { root = nullptr; }
    ~Book() { deleteBook(root); }

    void create();
    void display();
    void deleteBook(Node *temp);
};

void Book::create()
{
    root = new Node();

    cout << "Enter the book title: ";
    cin.ignore();
    getline(cin, root->name);

    cout << "Enter total number of chapters in the book: ";
    cin >> root->count;

    root->child = new Node *[root->count];

    for (int i = 0; i < root->count; i++)
    {
        root->child[i] = new Node();

        cout << "Enter name of chapter " << i + 1 << ": ";
        cin.ignore();
        getline(cin, root->child[i]->name);

        cout << "Enter the total number of sections in chapter " << i + 1 << ": ";
        cin >> root->child[i]->count;

        root->child[i]->child = new Node *[root->child[i]->count];

        for (int j = 0; j < root->child[i]->count; j++)
        {
            root->child[i]->child[j] = new Node();

            cout << "Enter name of section " << i + 1 << "." << j + 1 << ": ";
            cin.ignore();
            getline(cin, root->child[i]->child[j]->name);

            cout << "Enter the total number of sub-sections in section " << i + 1 << "." << j + 1 << ": ";
            cin >> root->child[i]->child[j]->count;

            root->child[i]->child[j]->child = new Node *[root->child[i]->child[j]->count];

            for (int k = 0; k < root->child[i]->child[j]->count; k++)
            {
                root->child[i]->child[j]->child[k] = new Node();

                cout << "Enter name of sub-section " << i + 1 << "." << j + 1 << "." << k + 1 << ": ";
                cin.ignore();
                getline(cin, root->child[i]->child[j]->child[k]->name);
            }
        }
    }
}

void Book::display()
{
    if (!root)
    {
        cout << "No book created yet." << endl;
        return;
    }

    cout << "Book Title: " << root->name << ", Total Chapters: " << root->count << endl;

    for (int i = 0; i < root->count; i++)
    {
        cout << "\tChapter " << i + 1 << ": " << root->child[i]->name << ", Sections: " << root->child[i]->count << endl;

        for (int j = 0; j < root->child[i]->count; j++)
        {
            cout << "\t\tSection " << i + 1 << "." << j + 1 << ": " << root->child[i]->child[j]->name << ", Sub-sections: " << root->child[i]->child[j]->count << endl;

            for (int k = 0; k < root->child[i]->child[j]->count; k++)
            {
                cout << "\t\t\tSub-section " << i + 1 << "." << j + 1 << "." << k + 1 << ": " << root->child[i]->child[j]->child[k]->name << endl;
            }
        }
    }
}

void Book::deleteBook(Node *temp)
{
    if (!temp)
        return;

    if (temp->child)
    {
        for (int i = 0; i < temp->count; i++)
        {
            deleteBook(temp->child[i]);
        }
        delete[] temp->child;
    }

    delete temp;
}

int main()
{
    Book book;
    int choice = 0; // Initialize choice to prevent undefined behavior

    while (choice != 3)
    {
        cout << "\n===== < Menu > =====" << endl;
        cout << "1) Create a Book." << endl;
        cout << "2) Open a Book." << endl;
        cout << "3) Exit." << endl;
        cout << "=====================\n"
             << endl;

        cout << "Enter your choice: ";
        cin >> choice; // Take input before switch statement

        switch (choice)
        {
        case 1:
            book.create();
            break;

        case 2:
            book.display();
            break;

        case 3:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Enter a valid choice." << endl;
        }
    }

    return 0;
}
