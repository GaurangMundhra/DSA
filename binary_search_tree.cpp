#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }

    if (head->data > val)
    {
        head->left = insert(head->left, val);
    }
    else
    {
        head->right = insert(head->right, val);
    }
    return head;
}

Node *getSuccessor(Node *curr)
{
    curr = curr->right;
    while (curr != NULL && curr->left != NULL)
    {
        curr = curr->left;
    }
    return curr;
}

Node *del(Node *head, int val)
{
    if (head == NULL)
        return NULL;

    if (head->data > val)
    {
        head->left = del(head->left, val);
    }
    else if (head->data < val)
    {
        head->right = del(head->right, val);
    }
    else
    {
        if (head->left == NULL)
        {
            Node *temp = head->right;
            delete head;
            return temp;
        }

        if (head->right == NULL)
        {
            Node *temp = head->left;
            delete head;
            return temp;
        }

        Node *succ = getSuccessor(head);
        head->data = succ->data;
        head->right = del(head->right, succ->data);
    }
    return head;
}

void invertTree(Node *head)
{
    if (head == NULL)
        return;
    invertTree(head->left);
    invertTree(head->right);
    swap(head->left, head->right);
}

void inorder(Node *head)
{
    if (head == NULL)
        return;
    inorder(head->left);
    cout << head->data << " ";
    inorder(head->right);
}

void preOrder(Node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    preOrder(head->left);
    preOrder(head->right);
}

void postOrder(Node *head)
{
    if (head == NULL)
        return;
    postOrder(head->left);
    postOrder(head->right);
    cout << head->data << " ";
}

void inorderNonRecursive(Node *head)
{
    if (head == NULL)
        return;

    stack<Node *> s;
    Node *curr = head;

    while (curr != NULL || !s.empty())
    {
        while (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";

        curr = curr->right;
    }
}

void preorderNonRecursive(Node *head)
{
    if (head == NULL)
        return;

    stack<Node *> s;
    s.push(head);

    while (!s.empty())
    {
        Node *curr = s.top();
        s.pop();

        cout << curr->data << " ";

        if (curr->right != NULL)
            s.push(curr->right);
        if (curr->left != NULL)
            s.push(curr->left);
    }
}

void postorderNonRecursive(Node *head)
{
    if (head == NULL)
        return;

    stack<Node *> s1, s2;
    s1.push(head);

    while (!s1.empty())
    {
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    while (!s2.empty())
    {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

int countNodes(Node *head)
{
    if (head == NULL)
        return 0;
    return 1 + countNodes(head->left) + countNodes(head->right);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node *root = NULL;

    while (true)
    {
        cout << "\nEnter your choice:" << endl;
        cout << "1. Insert a node" << endl;
        cout << "2. Delete a node" << endl;
        cout << "3. Traverse the BST using inorder with recursion" << endl;
        cout << "4. Traverse the BST using preorder with recursion" << endl;
        cout << "5. Traverse the BST using postorder with recursion" << endl;
        cout << "6. Traverse the BST using inorder without recursion" << endl;
        cout << "7. Traverse the BST using preorder without recursion" << endl;
        cout << "8. Traverse the BST using postorder without recursion" << endl;
        cout << "9. Invert the tree" << endl;
        cout << "10. Count total nodes" << endl;
        cout << "11. Exit" << endl;

        int choice, val;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the value of Node: ";
            cin >> val;
            root = insert(root, val);
            break;
        case 2:
            cout << "Enter the value to delete: ";
            cin >> val;
            root = del(root, val);
            break;
        case 3:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Preorder Traversal: ";
            preOrder(root);
            cout << endl;
            break;
        case 5:
            cout << "Postorder Traversal: ";
            postOrder(root);
            cout << endl;
            break;
        case 6:
            cout << "Inorder Traversal (non-recursive): ";
            inorderNonRecursive(root);
            cout << endl;
            break;
        case 7:
            cout << "Preorder Traversal (non-recursive): ";
            preorderNonRecursive(root);
            cout << endl;
            break;
        case 8:
            cout << "Postorder Traversal (non-recursive): ";
            postorderNonRecursive(root);
            cout << endl;
            break;
        case 9:
            invertTree(root);
            cout << "Tree inverted!" << endl;
            break;
        case 10:
            cout << "Total number of nodes: " << countNodes(root) << endl;
            break;

        case 11:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice! Try again." << endl;
        }
    }
    return 0;
}
