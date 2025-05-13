#ifndef MYSTACK_H
#define MYSTACK_H

#define MAX_SIZE 100  // Define max size of the stack

class MyStack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    MyStack() { top = -1; }

    void push(int x) {
        if (top >= MAX_SIZE - 1) {
            return;  // Stack Overflow
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            return -1;  // Stack Underflow
        }
        return arr[top--];
    }

    int peek() {
        if (top == -1) {
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

#endif
