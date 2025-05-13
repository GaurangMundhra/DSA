#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

void fibWithoutRec(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonacci series: " << a << " " << b << " ";

    for (int i = 2; i < n; i++) {
        int newNumber = a + b;
        cout << newNumber << " ";
        a = b;
        b = newNumber;
    }
    cout << endl;
}

int main() {
    int choice;
    int n;

    do {
        cout << "\nMenu:\n";
        cout << "1. Fibonacci using recursion\n";
        cout << "2. Fibonacci without recursion\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the position (n) for Fibonacci using recursion: ";
                cin >> n;
                cout << "The " << n << "th Fibonacci number is: " << fib(n) << endl;
                break;

            case 2:
                cout << "Enter the number of terms for Fibonacci series: ";
                cin >> n;
                if (n < 2) {
                    cout << "Please enter a number greater than or equal to 2." << endl;
                } else {
                    fibWithoutRec(n);
                }
                break;

            case 3:
                cout << "Exiting the program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
