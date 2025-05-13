#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = nullptr;
    }
};

class SinglyLinkedList
{
private:
    Node *head;

public:
    SinglyLinkedList()
    {
        head = nullptr;
    }

    // Insert at front
    void insertFront(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value)
    {
        Node *newNode = new Node(value);
        if (head == nullptr)
        {
            head = newNode;
            return;
        }
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at position (1-based indexing)
    void insertAtPosition(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position!\n";
            return;
        }

        if (pos == 1)
        {
            insertFront(value);
            return;
        }

        Node *newNode = new Node(value);
        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr)
        {
            cout << "Position out of range!\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from front
    void deleteFront()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteEnd()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == nullptr)
        {
            delete head;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at position (1-based indexing)
    void deleteAtPosition(int pos)
    {
        if (pos < 1 || head == nullptr)
        {
            cout << "Invalid position or empty list!\n";
            return;
        }

        if (pos == 1)
        {
            deleteFront();
            return;
        }

        Node *temp = head;

        for (int i = 1; i < pos - 1 && temp->next != nullptr; i++)
            temp = temp->next;

        if (temp->next == nullptr)
        {
            cout << "Position out of range!\n";
            return;
        }

        Node *delNode = temp->next;
        temp->next = delNode->next;
        delete delNode;
    }

    // Display list
    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty.\n";
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Main Function
int main()
{
    SinglyLinkedList list;
    int choice, value, pos;

    do
    {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Front\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Delete from Front\n5. Delete from End\n6. Delete from Position\n";
        cout << "7. Display List\n8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertFront(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertAtPosition(value, pos);
            break;
        case 4:
            list.deleteFront();
            break;
        case 5:
            list.deleteEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        case 7:
            list.display();
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 8);

    return 0;
}
