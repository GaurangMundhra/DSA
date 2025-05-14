#include <iostream>
#include <stack>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int data1) {
        data = data1;
        left = NULL;
        right = NULL;
    }
};

Node *insert(Node *root, int data) {
    if (root == NULL) {
        Node *new_node = new Node(data);
        return new_node;
    }
    if (root->data == data)
        return root;
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    return root;
}

Node *getSuccessor(Node *curr) {
    curr = curr->right;
    while (curr != nullptr && curr->left != nullptr)
        curr = curr->left;
    return curr;
}

Node *deletenode(Node *root, int x) {
    if (root == nullptr)
        return root;
    if (root->data > x)
        root->left = deletenode(root->left, x);
    else if (root->data < x)
        root->right = deletenode(root->right, x);
    else {
        if (root->left == nullptr) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (root->right == nullptr) {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *succ = getSuccessor(root);
        root->data = succ->data;
        root->right = deletenode(root->right, succ->data);
    }
    return root;
}

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void non_inorder(Node *root) {
    stack<Node *> s;
    Node *curr = root;
    while (curr != NULL || !s.empty()) {
        while (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        curr = s.top();
        s.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void preorder(Node *root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void non_preorder(Node *root) {
    if (root == NULL)
        return;
    stack<Node *> s;
    s.push(root);
    while (!s.empty()) {
        Node *curr = s.top();
        s.pop();
        cout << curr->data << " ";
        if (curr->right)
            s.push(curr->right);
        if (curr->left)
            s.push(curr->left);
    }
}

void postorder(Node *root) {
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void non_postorder(Node *root) {
    if (root == NULL)
        return;

    stack<Node *> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        Node *curr = s1.top();
        s1.pop();
        s2.push(curr);
        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
}

void mirror(Node *root) {
    if (root == nullptr)
        return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main() {
    Node *root = nullptr; // FIXED: Moved outside loop
    bool flag = true;

    while (flag) {
        int choice;
        cout << "\nMenu:\n";
        cout << "1. Insert node\n";
        cout << "2. Delete node\n";
        cout << "3. Recursive Inorder Traversal\n";
        cout << "4. Iterative Inorder Traversal\n";
        cout << "5. Recursive Preorder Traversal\n";
        cout << "6. Iterative Preorder Traversal\n";
        cout << "7. Recursive Postorder Traversal\n";
        cout << "8. Iterative Postorder Traversal\n";
        cout << "9. Mirror Tree\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1: {
            cout << "How many nodes do you want to insert: ";
            int n;
            cin >> n;
            if (n <= 0) break;

            cout << "Enter values of nodes: ";
            for (int i = 0; i < n; i++) {
                int x;
                cin >> x;
                root = insert(root, x);
            }
            break;
        }

        case 2: {
            cout << "Enter value to delete: ";
            int a;
            cin >> a;
            root = deletenode(root, a);
            break;
        }

        case 3:
            cout << "Recursive Inorder: ";
            inorder(root);
            cout << endl;
            break;

        case 4:
            cout << "Iterative Inorder: ";
            non_inorder(root);
            cout << endl;
            break;

        case 5:
            cout << "Recursive Preorder: ";
            preorder(root);
            cout << endl;
            break;

        case 6:
            cout << "Iterative Preorder: ";
            non_preorder(root);
            cout << endl;
            break;

        case 7:
            cout << "Recursive Postorder: ";
            postorder(root);
            cout << endl;
            break;

        case 8:
            cout << "Iterative Postorder: ";
            non_postorder(root);
            cout << endl;
            break;

        case 9:
            mirror(root);
            cout << "Tree has been mirrored.\n";
            break;

        case 10:
            cout << "Exiting program.\n";
            flag = false;
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}
