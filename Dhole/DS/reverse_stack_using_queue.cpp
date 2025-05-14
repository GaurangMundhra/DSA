#include <iostream>
using namespace std;

#define size 10

int stack[size];
int top = -1;

int queue[size];
int front = -1, rear = -1;

// Stack operations
bool isStackFull()
{
    return top == size - 1;
}

bool isStackEmpty()
{
    return top == -1;
}

void push(int x)
{
    if (isStackFull())
    {
        cout << "Stack is full!\n";
        return;
    }
    stack[++top] = x;
}

int pop()
{
    if (isStackEmpty())
    {
        cout << "Stack is empty!\n";
        return -1;
    }
    return stack[top--];
}

void printStack()
{
    if (isStackEmpty())
    {
        cout << "Stack is empty!\n";
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--)
        cout << stack[i] << " ";
    cout << endl;
}

// Queue operations (Linear Queue)
bool isQueueFull()
{
    return rear == size - 1;
}

bool isQueueEmpty()
{
    return front == -1 || front > rear;
}

void enqueue(int x)
{
    if (isQueueFull())
    {
        cout << "Queue is full!\n";
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue()
{
    if (isQueueEmpty())
    {
        cout << "Queue is empty!\n";
        return -1;
    }
    return queue[front++];
}

void printQueue()
{
    if (isQueueEmpty())
    {
        cout << "Queue is empty!\n";
        return;
    }
    cout << "Queue elements (front to rear): ";
    for (int i = front; i <= rear; i++)
        cout << queue[i] << " ";
    cout << endl;
}

// Reverse Stack using Queue
void reverseStackUsingQueue()
{
    if (isStackEmpty())
    {
        cout << "Stack is empty. Nothing to reverse!\n";
        return;
    }

    // Transfer Stack to Queue
    while (!isStackEmpty())
    {
        enqueue(pop());
    }

    // Transfer back Queue to Stack
    while (!isQueueEmpty())
    {
        push(dequeue());
    }

    cout << "Stack reversed using Queue!\n";
}

// Main menu
int main()
{
    int choice, val;
    bool running = true;

    while (running)
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Push to Stack\n";
        cout << "2. Pop from Stack\n";
        cout << "3. Print Stack\n";
        cout << "4. Enqueue to Queue\n";
        cout << "5. Dequeue from Queue\n";
        cout << "6. Print Queue\n";
        cout << "7. Reverse Stack using Queue\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push (-1 to stop): ";
            while (true)
            {
                cin >> val;
                if (val == -1)
                    break;
                push(val);
            }
            break;

        case 2:
            val = pop();
            if (val != -1)
                cout << val << " removed from Stack.\n";
            break;

        case 3:
            printStack();
            break;

        case 4:
            cout << "Enter value to enqueue (-1 to stop): ";
            while (true)
            {
                cin >> val;
                if (val == -1)
                    break;
                enqueue(val);
            }
            break;

        case 5:
            val = dequeue();
            if (val != -1)
                cout << val << " removed from Queue.\n";
            break;

        case 6:
            printQueue();
            break;

        case 7:
            reverseStackUsingQueue();
            break;

        case 8:
            running = false;
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}
