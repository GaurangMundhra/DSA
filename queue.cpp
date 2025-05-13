#define MAX_SIZE 5  
#include <iostream>
#include "MyStack.h"
#include "MyQueue.h"

using namespace std;

class circularQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    circularQueue() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = x;
        cout << "Inserted: " << x << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Underflow error\n";
            return;
        }
        cout << "Removed: " << arr[front] << endl;
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (front == (rear + 1) % MAX_SIZE);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX_SIZE;
        }
        cout << endl;
    }
};

class reverse {
public:
    void reverseStack(MyStack &st) {
        MyQueue q;
        while (!st.isEmpty()) {
            q.enqueue(st.pop());
        }
        while (!q.isEmpty()) {
            st.push(q.dequeue());
        }
        cout << "Stack reversed successfully!\n";
    }
};

int main() {
    circularQueue cq;
    MyStack st;
    reverse rev;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue (Circular Queue)\n";
        cout << "2. Dequeue (Circular Queue)\n";
        cout << "3. Display Circular Queue\n";
        cout << "4. Push to Stack\n";
        cout << "5. Pop from Stack\n";
        cout << "6. Reverse Stack\n";
        cout << "7. Display Stack\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;

            case 2:
                cq.dequeue();
                break;

            case 3:
                cq.display();
                break;

            case 4:
                cout << "Enter value to push: ";
                cin >> value;
                st.push(value);
                break;

            case 5:
                if (!st.isEmpty()) {
                    cout << "Popped value: " << st.pop() << endl;
                } else {
                    cout << "Stack is empty!" << endl;
                }
                break;

            case 6:
                rev.reverseStack(st);
                break;

            case 7: {
                cout << "Stack elements (Top to Bottom): ";
                MyStack temp = st;  
                while (!temp.isEmpty()) {
                    cout << temp.pop() << " ";
                }
                cout << endl;
                break;
            }

            case 8:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
