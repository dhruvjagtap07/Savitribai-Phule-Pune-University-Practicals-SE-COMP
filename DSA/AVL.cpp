// A Dictionary stores keywords and its meanings. Provide facility for adding new
// keywords, deleting keywords, updating values of any entry. Provide facility to display
// whole data sorted in ascending/ Descending order. Also find how many maximum
// comparisons may require for finding any keyword. Use Height balance tree and find the
// complexity for finding a keyword

#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string keyword, meaning;
    Node *left;
    Node *right;
    int height;

    Node(string key, string val)
    {
        keyword = key;
        meaning = val;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree
{
private:
    Node *root;

    int height(Node *n)
    {
        return n ? n->height : 0;
    }

    int balanceFactor(Node *n)
    {
        return n ? height(n->left) - height(n->right) : 0;
    }

    Node *rotateRight(Node *y)
    {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(height(y->left), height(y->right));
        x->height = 1 + max(height(x->left), height(x->right));

        return x;
    }

    Node *rotateLeft(Node *x)
    {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(height(x->left), height(x->right));
        y->height = 1 + max(height(y->left), height(y->right));

        return y;
    }

    Node *insert(Node *node, string key, string val)
    {
        if (!node)
            return new Node(key, val);

        if (key < node->keyword)
            node->left = insert(node->left, key, val);
        else if (key > node->keyword)
            node->right = insert(node->right, key, val);
        else
        {
            node->meaning = val; // Update
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        if (balance > 1 && key < node->left->keyword)
            return rotateRight(node);
        if (balance < -1 && key > node->right->keyword)
            return rotateLeft(node);
        if (balance > 1 && key > node->left->keyword)
        {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }
        if (balance < -1 && key < node->right->keyword)
        {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    Node *minValueNode(Node *node)
    {
        Node *current = node;
        while (current->left)
            current = current->left;
        return current;
    }

    Node *deleteNode(Node *root, string key)
    {
        if (!root)
            return root;

        if (key < root->keyword)
            root->left = deleteNode(root->left, key);
        else if (key > root->keyword)
            root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left || !root->right)
            {
                Node *temp = root->left ? root->left : root->right;
                if (!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else
                    *root = *temp;
                delete temp;
            }
            else
            {
                Node *temp = minValueNode(root->right);
                root->keyword = temp->keyword;
                root->meaning = temp->meaning;
                root->right = deleteNode(root->right, temp->keyword);
            }
        }

        if (!root)
            return root;

        root->height = 1 + max(height(root->left), height(root->right));
        int balance = balanceFactor(root);

        if (balance > 1 && balanceFactor(root->left) >= 0)
            return rotateRight(root);
        if (balance > 1 && balanceFactor(root->left) < 0)
        {
            root->left = rotateLeft(root->left);
            return rotateRight(root);
        }
        if (balance < -1 && balanceFactor(root->right) <= 0)
            return rotateLeft(root);
        if (balance < -1 && balanceFactor(root->right) > 0)
        {
            root->right = rotateRight(root->right);
            return rotateLeft(root);
        }

        return root;
    }

    void inOrder(Node *root)
    {
        if (root)
        {
            inOrder(root->left);
            cout << root->keyword << " : " << root->meaning << endl;
            inOrder(root->right);
        }
    }

    void reverseInOrder(Node *root)
    {
        if (root)
        {
            reverseInOrder(root->right);
            cout << root->keyword << " : " << root->meaning << endl;
            reverseInOrder(root->left);
        }
    }

    int search(Node *node, string key, int &comparisons)
    {
        if (!node)
            return -1;
        comparisons++;
        if (key == node->keyword)
        {
            cout << "Found: " << node->keyword << " => " << node->meaning << endl;
            return 1;
        }
        else if (key < node->keyword)
            return search(node->left, key, comparisons);
        else
            return search(node->right, key, comparisons);
    }

public:
    AVLTree()
    {
        root = nullptr;
    }

    void insert(string key, string meaning)
    {
        root = insert(root, key, meaning);
    }

    void deleteKey(string key)
    {
        root = deleteNode(root, key);
    }

    void update(string key, string newMeaning)
    {
        insert(key, newMeaning);
    }

    void displayAscending()
    {
        cout << "Dictionary in Ascending Order:\n";
        inOrder(root);
    }

    void displayDescending()
    {
        cout << "Dictionary in Descending Order:\n";
        reverseInOrder(root);
    }

    void find(string key)
    {
        int comparisons = 0;
        if (search(root, key, comparisons) == -1)
            cout << "Keyword not found!\n";
        cout << "Comparisons: " << comparisons << endl;
    }

    void maxComparisons()
    {
        cout << "Maximum comparisons (height of tree): " << height(root) << endl;
    }
};

int main()
{
    AVLTree dict;
    int choice;
    string keyword, meaning;

    do
    {
        cout << "\n====== Dictionary Menu ======\n";
        cout << "1. Add Keyword\n";
        cout << "2. Update Meaning\n";
        cout << "3. Search Keyword\n";
        cout << "4. Display Dictionary (Ascending)\n";
        cout << "5. Display Dictionary (Descending)\n";
        cout << "6. Delete Keyword\n";
        cout << "7. Max Comparisons to Find\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter keyword: ";
            getline(cin, keyword);
            cout << "Enter meaning: ";
            getline(cin, meaning);
            dict.insert(keyword, meaning);
            break;
        case 2:
            cout << "Enter keyword to update: ";
            getline(cin, keyword);
            cout << "Enter new meaning: ";
            getline(cin, meaning);
            dict.update(keyword, meaning);
            break;
        case 3:
            cout << "Enter keyword to search: ";
            getline(cin, keyword);
            dict.find(keyword);
            break;
        case 4:
            dict.displayAscending();
            break;
        case 5:
            dict.displayDescending();
            break;
        case 6:
            cout << "Enter keyword to delete: ";
            getline(cin, keyword);
            dict.deleteKey(keyword);
            break;
        case 7:
            dict.maxComparisons();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
