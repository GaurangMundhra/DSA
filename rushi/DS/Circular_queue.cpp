#include <iostream>
using namespace std;

#define size 10

int stack[size]; // Unused stack — can be removed if not needed
int top = -1;
int queue[size];
int front = -1, rear = -1;

bool isQueueFull()
{
    return (rear + 1) % size == front;
}

bool isQueueEmpty()
{
    return front == -1;
}

bool enqueue(int x)
{
    if (isQueueFull())
    {
        cout << "Queue is full\n" << endl;
        return false;
    }

    if (isQueueEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }

    queue[rear] = x;
    cout << x << " inserted into Queue\n";
    return true;
}

int dequeue()
{
    if (isQueueEmpty())
    {
        cout << "Queue empty\n" << endl;
        return -1;
    }

    int val = queue[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }

    return val;
}

void printQueue()
{
    if (isQueueEmpty())
    {
        cout << "Queue is empty\n" << endl;
        return;
    }

    cout << "Queue element: ";
    int curr = front;
    while (curr != rear)
    {
        cout << queue[curr] << " ";
        curr = (curr + 1) % size;
    }
    cout << queue[curr] << endl;
}

int main()
{
    bool loop1 = true;
    int v;

    while (loop1)
    {
        cout << "Choose what you want to perform in implementation of Circular Queue\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\n\n";

        int a;
        cout << "Enter choice: ";
        cin >> a;
        cout << "\n";

        switch (a)
        {
        case 1:
        {
            bool flag = true;
            cout << "Enter -1 to Exit the Enqueue process!\n";
            while (flag)
            {
                int x;
                cin >> x;
                if (x == -1)
                    break;
                flag = enqueue(x);
            }
            break;
        }

        case 2:
            v = dequeue();
            if (v != -1)
                cout << v << " Removed from Queue\n" << endl;
            break;

        case 3:
            printQueue();
            cout << endl;
            break;

        case 4:
            loop1 = false;
            cout << "Exiting Circular Queue" << endl;
            break;

        default:
            cout << "Invalid choice, try again.\n";
            break;
        }
    }

    return 0;
}
