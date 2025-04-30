#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    bool lthread, rthread;

    Node(int value = 0)
    {
        data = value;
        left = right = nullptr;
        lthread = rthread = false;
    }
};

// Normal Binary Tree for comparison
class NormalBinaryTree
{
private:
    Node *root;
    int normalTraversalCount = 0;

    void noramlInorder(Node *root)
    {
        stack<Node *> st;
        Node *curr = root;

        while (curr != nullptr || !st.empty())
        {
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
                normalTraversalCount++; // Counting left movement (stack usage)
            }

            curr = st.top();
            st.pop();

            cout << curr->data << " ";

            curr = curr->right;
            normalTraversalCount++; // Counting right movement
        }

        cout << endl;
    }

public:
    NormalBinaryTree()
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

    void inorder()
    {
        noramlInorder(root);
        cout << endl;
    }

    int getTraversalCount()
    {
        return normalTraversalCount;
    }

    Node *getRoot()
    {
        return root;
    }
};

// Threaded Binary Tree
class ThreadedBinaryTree
{
private:
    Node *root;
    Node *prev;
    int threadedTraversalCount = 0;

    void convertHelper(Node *curr)
    {
        if (!curr)
            return;

        convertHelper(curr->left);

        if (curr->left == nullptr)
        {
            curr->lthread = true;
            curr->left = prev;
        }

        if (prev && prev->right == nullptr)
        {
            prev->rthread = true;
            prev->right = curr;
        }

        prev = curr;
        convertHelper(curr->right);
    }

public:
    ThreadedBinaryTree(Node *normalRoot)
    {
        // Create a deep copy of the normal tree
        root = cloneTree(normalRoot);
        prev = nullptr;
        convertHelper(root);
    }

    Node *cloneTree(Node *node)
    {
        if (!node)
            return nullptr;

        Node *newNode = new Node(node->data);
        newNode->left = cloneTree(node->left);
        newNode->right = cloneTree(node->right);
        return newNode;
    }

    void inorder()
    {
        Node *curr = root;

        // Go to leftmost node
        while (curr && !curr->lthread)
            curr = curr->left;

        while (curr)
        {
            cout << curr->data << " ";
            threadedTraversalCount++;

            if (curr->rthread)
            {
                curr = curr->right;
            }
            else
            {
                curr = curr->right;
                while (curr && !curr->lthread)
                    curr = curr->left;
            }
        }
        cout << endl;
    }

    int getTraversalCount()
    {
        return threadedTraversalCount;
    }
};

// ===================== MAIN =====================

int main()
{
    int n, value;
    cout << "Enter number of nodes: ";
    cin >> n;

    NormalBinaryTree normalTree;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter node value: ";
        cin >> value;
        normalTree.insertNode(value);
    }

    cout << "\nNormal Inorder Traversal: ";
    normalTree.inorder();
    cout << "Operations (Normal Inorder): " << normalTree.getTraversalCount() << endl;

    ThreadedBinaryTree threadedTree(normalTree.getRoot());
    cout << "\nThreaded Inorder Traversal: ";
    threadedTree.inorder();
    cout << "Operations (Threaded Inorder): " << threadedTree.getTraversalCount() << endl;

    return 0;
}
