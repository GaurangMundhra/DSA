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

Node *atend(Node *head, int val)
{
    Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    Node *new_node = new Node(val);
    curr->next = new_node;
    return head;
}

Node *atbegin(Node *head, int val)
{
    Node *new_node = new Node(val);
    new_node->next = head;
    return new_node;
}

Node *atanyk(Node *head, int val, int k)
{
    Node *curr = head;
    Node *temp = new Node(val);
    for (int i = 1; i < k; i++)
    {
        curr = curr->next;
    }
    Node *next = curr->next;
    curr->next = temp;
    temp->next = next;
    return head;
}

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

Node *deleten(Node *head, int d)
{
    // Handle case when deleting head (position 0)
    if (d == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *curr = head;
    for (int i = 0; i < d - 1; i++)
    {
        curr = curr->next;
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

    cout << "\n";
    string addd = " -> ";
    move = head;

    cout << "Singly LinkedList: \n";
    while (move != NULL)
    {
        if (move->next == NULL)
            addd = " ";
        cout << move->data << addd;
        move = move->next;
    }

    cout << endl;
    bool flag = true;
    Node *curr; // 👉 added this here

    while (flag)
    {
        cout << "\nWhat would you like to do: " << endl;
        cout << "1. Insert Node\n2. Find nodes having even numbers\n3. Delete Node\n4. Exit\n\n";
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        cout << "\n";
        string ad;

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

            curr = head;
            ad = " -> ";
            while (curr != NULL)
            {
                if (curr->next == NULL)
                    ad = " ";
                cout << curr->data << ad;
                curr = curr->next;
            }
            cout << endl;
            break;

        case 2:
            even_node(head);
            break;

        case 3:
            cout << "\nEnter the position to delete: ";
            int d;
            cin >> d;
            head = deleten(head, d);
            curr = head;
            ad = " -> ";
            while (curr != NULL)
            {
                if (curr->next == NULL)
                    ad = " ";
                cout << curr->data << ad;
                curr = curr->next;
            }
            cout << endl;
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
