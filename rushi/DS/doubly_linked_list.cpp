#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int data1)
    {
        data = data1;
        next = NULL;
        prev = NULL;
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
    new_node->prev = curr;

    return head;
}

Node *atbegin(Node *head, int val)
{
    Node *curr = head;
    Node *new_node = new Node(val);

    new_node->next = curr;
    curr->prev = new_node;

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
    temp->prev = curr;
    next->prev = temp;

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

Node *delete_node(Node *head, int d)
{
    Node *curr = head;
    // 1 2 3 4 5
    for (int i = 0; i < d; i++)
    {
        curr = curr->next;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;

    delete (curr);

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
    Node *curr = NULL;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        move->next = temp;
        temp->prev = move;
        move = temp;
    }
    cout << "\n";

    string addd = " <--> ";
    move = head;
    cout << "Doubly LinkedList: \n";

    while (move != NULL)
    {
        if (move->next == NULL)
            addd = " ";
        cout << move->data << addd;
        move = move->next;
    }

    cout << endl;
    bool flag = true;

    while (flag)
    {
        cout << "\nWhat would you like to do: " << endl;
        cout << "1. Insert Node\n2. Find nodes having even numbers\n3.Delete Node\n4.Exit\n\n ";

        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        cout << "\n";

        string ad;
        switch (choice)
        {
        case 1:
            cout << "\nWhere would you like to insert: " << endl;
            cout << "1. at end\n2. at begining\n3. at a positionk\n\n ";

            int c, k, d;
            cout << "Enter choice: ";
            cin >> c;
            cout << "\nEnter value for node: ";
            int val;
            cin >> val;

            switch (c)
            {
            case 1:
                head = atend(head, val);
                curr = head;
                ad = " <--> ";
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
                head = atbegin(head, val);
                curr = head;
                ad = " <--> ";
                while (curr != NULL)
                {
                    if (curr->next == NULL)
                        ad = " ";
                    cout << curr->data << ad;
                    curr = curr->next;
                }
                cout << endl;
                break;

            case 3:
                cout << "\nEnter the position to insert: ";
                cin >> k;
                head = atanyk(head, val, k);
                curr = head;
                ad = " <--> ";
                while (curr != NULL)
                {
                    if (curr->next == NULL)
                        ad = " ";
                    cout << curr->data << ad;
                    curr = curr->next;
                }
                cout << endl;
                break;

            default:
                break;
            }
            break;

        case 2:
            even_node(head);
            break;

        case 3:
            cout << "\nEnter the position to delete: ";
            cin >> d;

            head = delete_node(head, d);
            curr = head;

            ad = " <--> ";

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
            cout << "Exiting Program...";
            break;

        default:
            break;
        }
    }
    return 0;
}