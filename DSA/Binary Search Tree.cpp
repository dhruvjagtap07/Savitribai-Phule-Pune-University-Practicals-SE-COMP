// Beginning with an empty binary search tree, Construct binary search tree by inserting
// the values in the order given. After constructing a binary tree -
// i. Insert new node,
// ii. Find number of nodes in longest path from root,
// iii. Minimum data value found in the tree,
// iv. Change a tree so that the roles of the left and right pointers are swapped at every node,
// v. Search a value

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int value = 0)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BinaryTree
{
private:
    Node *root;

public:
    BinaryTree()
    {
        root = nullptr;
    }

    void insertNode(int value)
    {
        Node *newNode = new Node(value);

        if (!root)
        {
            root = newNode;
            return;
        }

        Node *temp = root;
        Node *parent = nullptr;

        while (temp != nullptr)
        {
            parent = temp;

            if (value < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }

        if (value < parent->data)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    int height(Node *node)
    {
        if (!node)
            return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    int height()
    {
        if (!root)
        {
            cout << "Tree is empty." << endl;
        }
        return height(root);
    }

    int minimum(Node *node)
    {
        if (!node)
            return -1;

        while (node->left != nullptr)
        {
            node = node->left;
        }

        return node->data;
    }

    int minimum()
    {
        if (!root)
        {
            cout << "Tree is empty." << endl;
        }
        return minimum(root);
    }

    int maximum(Node *node)
    {
        if (!node)
            return -1;

        while (node->right != nullptr)
        {
            node = node->right;
        }

        return node->data;
    }

    int maximum()
    {
        if (!root)
        {
            cout << "Tree is empty." << endl;
        }
        return maximum(root);
    }

    void mirror(Node *node)
    {
        if (!node)
            return;

        swap(node->left, node->right); // std::swap

        mirror(node->left);
        mirror(node->right);
    }

    void mirror()
    {
        if (!root)
        {
            cout << "Tree is empty." << endl;
            return;
        }
        mirror(root);
    }

    bool search(int value)
    {
        Node *temp = root;

        while (temp != nullptr)
        {
            if (temp->data == value)
                return true;
            else if (value < temp->data)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return false;
    }

    void inorder(Node *node)
    {
        if (!node)
            return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    void inorder()
    {
        if (!root)
        {
            cout << "Tree is empty." << endl;
            return;
        }
        inorder(root);
        cout << endl;
    }

    void preorder(Node *node)
    {
        if (!node)
            return;

        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    void preorder()
    {
        if (!root)
        {
            cout << "Tree is empty." << endl;
            return;
        }
        preorder(root);
        cout << endl;
    }

    void postorder(Node *node)
    {
        if (!node)
            return;

        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    void postorder()
    {
        if (!root)
        {
            cout << "Tree is empty." << endl;
            return;
        }
        preorder(root);
        cout << endl;
    }

    void display()
    {
        int choice;
        cout << "===< Display MENU >===" << endl;
        cout << "1) Preorder Display" << endl;
        cout << "2) Inorder Display" << endl;
        cout << "3) Postorder Display" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            preorder();
            break;
        case 2:
            inorder();
            break;
        case 3:
            postorder();
            break;
        default:
            cout << "Please enter correct choice!" << endl;
        }
    }
};

int main()
{
    BinaryTree tree;

    int choice = 0;

    while (true)
    {
        cout << "======= MNEU =======" << endl;
        cout << "1) Create a BST." << endl;
        cout << "2) Insert a node." << endl;
        cout << "3) Height of the tree." << endl;
        cout << "4) Minimum & maximum value." << endl;
        cout << "5) Mirror Image." << endl;
        cout << "6) Search." << endl;
        cout << "7) Display." << endl;
        cout << "8) EXIT." << endl;
        cout << "====================" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
        {
            int n;
            cout << "Enter number of nodes: ";
            cin >> n;
            cout << "Enter values: ";
            for (int i = 0; i < n; i++)
            {
                int value;
                cin >> value;
                tree.insertNode(value);
            }
            break;
        }
        case 2:
        {
            int value;
            cout << "Enter value to insert: ";
            cin >> value;
            tree.insertNode(value);
            break;
        }
        case 3:
        {
            cout << "Height of the tree: " << tree.height() << endl;
            break;
        }
        case 4:
        {
            cout << "Minimum value in the tree: " << tree.minimum() << endl;
            cout << "Maximum value in the tree: " << tree.maximum() << endl;
            break;
        }
        case 5:
        {
            tree.mirror();
            cout << "Tree mirrored." << endl;
            break;
        }
        case 6:
        {
            int value;
            cout << "Enter value to search: ";
            cin >> value;
            bool result = tree.search(value);
            if (result)
            {
                cout << "Node Found!" << endl;
            }
            else
            {
                cout << "Node not found!" << endl;
            }
            break;
        }
        case 7:
        {
            tree.display();
            break;
        }
        case 8:
            return 0;
        }
    }

    return 0;
}