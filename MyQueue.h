#ifndef MYQUEUE_H
#define MYQUEUE_H

#define MAX_SIZE 5  // Define max size of the queue

class MyQueue {
private:
    int arr[MAX_SIZE];
    int front, rear;

public:
    MyQueue() {
        front = rear = -1;
    }

    void enqueue(int x) {
        if (rear >= MAX_SIZE - 1) {
            return;  // Queue Overflow
        }
        if (front == -1) front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        if (front == -1 || front > rear) {
            return -1;  // Queue Underflow
        }
        return arr[front++];
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};

#endif
