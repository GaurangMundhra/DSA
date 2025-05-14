#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data1)
    {
        data = data1;
        next = NULL;
    }
};

// Function to print the list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        if (temp->next != NULL)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

// Function to insert at the end
Node *atend(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val); // If the list is empty, create a new node.
    }

    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    Node *new_node = new Node(val);
    curr->next = new_node;
    return head;
}

// Function to insert at the beginning
Node *atbegin(Node *head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    return new_node;
}

// Function to insert at a specific position k
Node *atanyk(Node *head, int val, int k)
{
    if (k == 0)
    {
        return atbegin(head, val);
    }

    Node *curr = head;
    for (int i = 1; i < k && curr != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr == NULL)
    {
        cout << "Invalid position\n";
        return head;
    }

    Node *temp = new Node(val);
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

// Function to print even nodes
void even_node(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data % 2 == 0)
            cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

// Function to delete node at a specific position
Node *deleten(Node *head, int d)
{
    if (head == NULL)
        return head;

    if (d == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *curr = head;
    for (int i = 0; i < d - 1 && curr->next != NULL; i++)
    {
        curr = curr->next;
    }

    if (curr->next == NULL)
    {
        cout << "Invalid position\n";
        return head;
    }

    Node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return head;
}

int main()
{
    cout << "Enter Number of elements you want to add: ";
    int n;
    cin >> n;
    cout << "\nEnter elements: ";

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = new Node(arr[0]);
    Node *move = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        move->next = temp;
        move = temp;
    }

    // Initial print of the linked list
    cout << "\nSingly LinkedList: \n";
    printList(head);

    bool flag = true;
    Node *curr; // Declare this here to use in the loop

    while (flag)
    {
        cout << "\nWhat would you like to do: " << endl;
        cout << "1. Insert Node\n2. Find nodes having even numbers\n3. Delete Node\n4. Exit\n\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        cout << "\n";

        switch (choice)
        {
        case 1:
            cout << "\nWhere would you like to insert: " << endl;
            cout << "1. at end\n2. at beginning\n3. at a position k\n\n";

            int c, k;
            cout << "Enter choice: ";
            cin >> c;

            cout << "\nEnter value for node: ";
            int val;
            cin >> val;

            switch (c)
            {
            case 1:
                head = atend(head, val);
                break;
            case 2:
                head = atbegin(head, val);
                break;
            case 3:
                cout << "\nEnter the position to insert: ";
                cin >> k;
                head = atanyk(head, val, k);
                break;
            default:
                break;
            }

            // Print updated list
            printList(head);
            break;

        case 2:
            even_node(head);
            break;

        case 3:
            cout << "\nEnter the position to delete: ";
            int d;
            cin >> d;
            head = deleten(head, d);

            // Print updated list
            printList(head);
            break;

        case 4:
            flag = false;
            cout << "Exiting Program..." << endl;
            break;

        default:
            break;
        }
    }
    return 0;
}
