#include <iostream>
#include <algorithm>
using namespace std;

// Node structure
struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;

    Node(int value)
    {
        key = value;
        left = right = nullptr;
        height = 1;
    }
};

// Get height of node
int getHeight(Node *node)
{
    return node ? node->height : 0;
}

// Get balance factor
int getBalance(Node *node)
{
    return node ? getHeight(node->left) - getHeight(node->right) : 0;
}

// Update height of a node
void updateHeight(Node *node)
{
    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
}

// Right rotate
Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    // Rotation
    x->right = y;
    y->left = T2;

    // Update heights
    updateHeight(y);
    updateHeight(x);

    return x;
}

// Left rotate
Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    // Rotation
    y->left = x;
    x->right = T2;

    // Update heights
    updateHeight(x);
    updateHeight(y);

    return y;
}

// Insert into AVL tree
Node *insert(Node *node, int key)
{
    if (!node)
        return new Node(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node; // no duplicate keys

    updateHeight(node);
    int balance = getBalance(node);

    // Balance cases
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

// Find node with minimum value
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current->left)
        current = current->left;
    return current;
}

// Delete node from AVL tree
Node *deleteNode(Node *root, int key)
{
    if (!root)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
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
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root)
        return root;

    updateHeight(root);
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Inorder traversal
void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver code
int main()
{
    Node *root = nullptr;
    int n, val, delVal, choice;

    cout << "How many values do you want to insert? ";
    cin >> n;

    cout << "Enter values:\n";
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nInorder traversal after insertion:\n";
    inorder(root);
    cout << endl;

    cout << "\nDo you want to delete a node? (1 for Yes / 0 for No): ";
    cin >> choice;

    while (choice)
    {
        cout << "Enter value to delete: ";
        cin >> delVal;
        root = deleteNode(root, delVal);

        cout << "\nInorder traversal after deletion:\n";
        inorder(root);
        cout << endl;

        cout << "\nDo you want to delete another node? (1 for Yes / 0 for No): ";
        cin >> choice;
    }

    cout << "\nFinal inorder traversal:\n";
    inorder(root);
    cout << endl;

    return 0;
}
