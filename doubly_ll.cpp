#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() {
        head = NULL;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int pos, int data) {
        Node* newNode = new Node(data);
        if (pos == 0) {
            newNode->next = head;
            if (head != NULL) head->prev = newNode;
            head = newNode;
            return;
        }
        Node* temp = head;
        for (int i = 0; temp != NULL && i < pos - 1; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
        newNode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
    
        Node* curr = head;
    
        if (pos == 0) {
            head = head->next;
            if (head != NULL) head->prev = NULL;
            delete curr;
            return;
        }
    
        for (int i = 0; curr != NULL && i < pos; i++) {
            curr = curr->next;
        }
    
        if (curr == NULL) {
            cout << "Invalid position!" << endl;
            return;
        }
    
        if (curr->next != NULL) {
            curr->next->prev = curr->prev;
        }
    
        if (curr->prev != NULL) {
            curr->prev->next = curr->next;
        }
    
        delete curr;
    }
    

    void printEvenNodes() {
        Node* temp = head;
        cout << "Even numbers in the list: ";
        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                cout << temp->data << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void display() {
        Node* temp = head;
        cout << "Doubly Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, data, pos;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert at end\n";
        cout << "2. Insert at position\n";
        cout << "3. Delete a node at position\n";
        cout << "4. Display even numbers\n";
        cout << "5. Display list\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data to insert: ";
                cin >> data;
                dll.insertAtEnd(data);
                break;
            case 2:
                cout << "Enter position and data to insert: ";
                cin >> pos >> data;
                dll.insertAtPosition(pos, data);
                break;
            case 3:
                cout << "Enter position to delete: ";
                cin >> pos;
                dll.deleteNode(pos);
                break;
            case 4:
                dll.printEvenNodes();
                break;
            case 5:
                dll.display();
                break;
            case 6:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    }
}
